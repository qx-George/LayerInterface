// IPLayer.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "IPLayer.h"
#pragma comment(lib, "../Debug/LinkLayer.lib")
#include "../LinkLayer/LinkLayer.h"


CIPLayer::CIPLayer(MsgList &sendBuf, MsgList &rcvBuf) : CLayerInterface(sendBuf, rcvBuf)
{
	m_pClientSendBuf = sendBuf;
	m_pClientRcvBuf = rcvBuf;
	pServerLayer = new CLinkLayer(mySendBuf, myRecvBuf);
	bHasServerLayer = true;
	bStop = false;
	isRoute = false;
	setHeadTailLen(80, 0);
}


CIPLayer::~CIPLayer()
{
}


void CIPLayer::addHead()
{
	char data[] = "IPLayer head --- ";
	memcpy(m_pDatagram->pHead, data, sizeof(data));
}

