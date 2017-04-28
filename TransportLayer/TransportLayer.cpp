// TransportLayer.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "TransportLayer.h"
#pragma comment(lib, "../Debug/IPLayer.lib")
#include "../IPLayer/IPLayer.h"
#include "UDP.h"
#include "TCP.h"

// This is an example of an exported variable
TRANSPORTLAYER_API int nTransportLayer=0;

// This is an example of an exported function.
TRANSPORTLAYER_API int fnTransportLayer(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see TransportLayer.h for the class definition
CTransportLayer::CTransportLayer(void)
{
	pServerLayer = new CIPLayer(mySendBuf, myRecvBuf);
	udp = new CUDP(udpSendBuf, recvBuf);
	setHeadTailLen(0, 0);
	udp->outerLayer = this;
	tcp = new CTCP(tcpSendBuf, recvBuf);
	tcp->outerLayer = this;
	bHasServerLayer = true;
	bStop = false;
	index = -1;
	mailslot.createMailSlot(0);	// ��������
	linkslot.createMailSlot(1);	// �������
}

/*
CTransportLayer::CTransportLayer(std::vector<MsgList> &sendBufVec, std::vector<MsgList> &recvBufVec) : pClientSendBuf(sendBufVec), pClientRcvBuf(recvBufVec)
{
	pServerLayer = new CIPLayer(mySendBuf, myRecvBuf);
	udp = new CUDP(udpSendBuf, recvBuf);
	setHeadTailLen(0, 0);
	udp->outerLayer = this;
	tcp = new CTCP(tcpSendBuf, recvBuf);
	tcp->outerLayer = this;
	bHasServerLayer = true;
	bStop = false;
	index = -1;
	mailslot.createMailSlot(0);
}
*/


bool CTransportLayer::init() {
	bool ret = false;
	udp->init();
	tcp->init();
	ret = CLayerInterface::init();
	return ret;
}

void CTransportLayer::run()
{
	hThread = CreateThread(NULL, 0, layerThread, this, 0, NULL);
	//udp->run(); // �˴�ע��ͬ������
	tcp->run();
	if (pServerLayer != NULL)
	{
		pServerLayer->run();
	}
}

int CTransportLayer::connect()
{
	linkslot.read(conn);
	// �ڴ˽�һ������TCP���ӣ���������
	return -1;
}

void CTransportLayer::recvTransfer()
{
	if (isBufferReady(SERVER))
	{
		*m_pDatagram = getData(SERVER);
		unpack();
		demultiplex(*m_pDatagram);
	}
}


void CTransportLayer::sendTransfer()
{
	// ���ȼ���Ƿ����µ�����
	connect();
	//if (isBufferReady(CLIENT))
	{
		/*
		Datagram datagram = getData(CLIENT);
		// �������жϽ��Ӹ��ĸ�Э��ȥ�������ò���
		multiplex(datagram);
		*/
		multiplex();
	}
}

void CTransportLayer::multiplex()
{
	Datagram datagram;
	char *msg;
	int length;
	if (mailslot.read(msg, length))
	{
		datagram.m_nMegLen = length;
		datagram.pHead = msg;
		tcpSendBuf.push(datagram);
	}
	
}

void CTransportLayer::multiplex(Datagram data){
	// ����Э����봦�����
	// udpSendBuf.push(data);
	tcpSendBuf.push(data);
}

void CTransportLayer::demultiplex(Datagram data){
	// ����Э����봦�����
	//pClientRcvBuf[0].push(data);
	mailslot.open(conn.srcPort);
	mailslot.write(data.pData, data.m_nMegLen);
	delete[] data.pHead;
}

Datagram CTransportLayer::getData(int lable) {
	/*
	if (lable == CLIENT)
	{
		return pClientSendBuf[index].pop();
	}
	else {
		return recvBuf.pop();
	}
	*/
	return recvBuf.pop();
}

Datagram CTransportLayer::getDatagram()
{
	return myRecvBuf.pop();
}

bool CTransportLayer::isRecvBufEmpty()
{
	return myRecvBuf.empty();
}

bool CTransportLayer::isBufferReady(int lable) {
	/*
	if (lable == CLIENT)
	{
		for (index = 0; index < pClientSendBuf.size(); index++)
		{
			if (!pClientSendBuf[index].empty())
			{
				return true;
			}
		}
		return false;
	}
	else {
		return (!recvBuf.empty());
	}
	*/

	return (!recvBuf.empty());
}


