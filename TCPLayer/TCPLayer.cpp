// TCPLayer.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "TCPLayer.h"
#pragma comment(lib, "../Debug/IPLayer.lib")
#include "../IPLayer/IPLayer.h"

CTCP::CTCP(MsgList &sendBuf, MsgList &rcvBuf) : CLayerInterface(sendBuf, rcvBuf)
{
	m_pClientSendBuf = sendBuf;
	m_pClientRcvBuf = rcvBuf;
	pServerLayer = new CIPLayer(mySendBuf, myRecvBuf);
	bHasServerLayer = true;
	bStop = false;
	m_nMsgHeadLen = 80;
	m_nMsgTailLen = 0;

	m_TCPConnect.m_pCTCP = this;
	m_pRDTransfer->m_pCTCP = this;
}


CTCP::~CTCP()
{
}


void CTCP::addHead()
{
	char data[] = "TransportLayer head --- ";
	memcpy(m_pDatagram->pHead, data, sizeof(data));
}
