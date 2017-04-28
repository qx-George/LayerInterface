// UDPLayer.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "CUDP.h"
#pragma comment(lib, "../Debug/IPLayer.lib")
#include "../IPLayer/IPLayer.h"

CUDP::CUDP(MsgList &sendBuf, MsgList &rcvBuf) : CLayerInterface(sendBuf, rcvBuf)
{
	m_pClientSendBuf = sendBuf;
	m_pClientRcvBuf = rcvBuf;
	// 当层实例化下层
	pServerLayer = new CIPLayer(mySendBuf, myRecvBuf);
	bHasServerLayer = true;
	bStop = false;
	m_nMsgHeadLen = 80;
	m_nMsgTailLen = 0;
}

void CUDP::addClient(MsgList sendBuf, MsgList rcvBuf) {
	m_MsgListSendQue.push_back(&sendBuf);
	m_MsgListRecvQue.push_back(&rcvBuf);
}

CUDP::~CUDP()
{
}

bool CUDP::init() {
	bool ret = false;
	
	ret = CLayerInterface::init();
	return ret;
}

void CUDP::addHead()
{
	char data[] = "TransportLayer head --- ";
	memcpy(m_pDatagram->pHead, data, sizeof(data));

	// add check function ;
}
