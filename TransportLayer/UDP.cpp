#include "stdafx.h"
#include "UDP.h"
#include "TransportLayer.h"

CUDP::CUDP(MsgList &sendBuf, MsgList &rcvBuf) : CLayerInterface(sendBuf, rcvBuf)
{
	m_pClientSendBuf = sendBuf;
	m_pClientRcvBuf = rcvBuf;
	// 当层实例化下层
	bHasServerLayer = false;
	bStop = false;
	m_nMsgHeadLen = 80;
	m_nMsgTailLen = 0;
}

CUDP::~CUDP()
{
}


void CUDP::addHead()
{
	char data[] = "UDP head --- ";
	memcpy(m_pDatagram->pHead, data, sizeof(data));

	// add check function ;
}


bool CUDP::sendData(Datagram datagram)
{
	return outerLayer->sendData(datagram);
}

Datagram CUDP::getData(int lable)
{
	if (lable == CLIENT)
	{
		return m_pClientSendBuf.pop();
	}
	else {
		return outerLayer->getDatagram();
	}
}

bool CUDP::isBufferReady(int lable) {
	if (lable == CLIENT)
	{
		return (!m_pClientSendBuf.empty());
	}
	else {
		return (!outerLayer->isRecvBufEmpty());
	}
}