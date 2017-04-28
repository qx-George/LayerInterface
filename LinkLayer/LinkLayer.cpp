// LinkLayer.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "LinkLayer.h"
#include <iostream>

CLinkLayer::CLinkLayer(MsgList &sendBuf, MsgList &rcvBuf) : CLayerInterface(sendBuf, rcvBuf), m_ARPProto(this)
{
	m_pClientSendBuf = sendBuf;
	m_pClientRcvBuf = rcvBuf;
	bHasServerLayer = false;
	bStop = false;
	m_nMsgHeadLen = 80;
	m_nMsgTailLen = 30;
}

CLinkLayer::~CLinkLayer()
{
}


void CLinkLayer::addHead()
{
	char data[] = "LinkLayer head --- ";
	memcpy(m_pDatagram->pHead, data, sizeof(data));
}

void CLinkLayer::addTail()
{
	char data[] = " --- LinkLayer Tail";
	memcpy(m_pDatagram->pTail, data, sizeof(data));
}


void CLinkLayer::sendTransfer()
{
	if (isBufferReady(CLIENT))
	{
		Datagram datagram = getData(CLIENT);
		package(datagram);
		char *p = m_pDatagram->pHead;			//����ʹ��
		//delete[] p;
		std::cout << "�������н����" << p << p+ 80<< p+160 <<p+240<<p+246<< std::endl;
		//�޸�ָ��  ����
		m_pDatagram->pData = m_pDatagram->pHead;
		myRecvBuf.push(*m_pDatagram);
	}
}

