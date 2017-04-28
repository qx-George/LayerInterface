// LayerInterface.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "LayerInterface.h"

// see LayerInterface.h for the class definition
// 不使用数据传递
CLayerInterface::CLayerInterface() : CLayerInterface(mySendBuf, myRecvBuf)
{
}

CLayerInterface::CLayerInterface(MsgList &sendBuf, MsgList &rcvBuf) : m_pClientSendBuf(sendBuf), m_pClientRcvBuf(rcvBuf)
{
	pServerLayer = NULL;
	bHasServerLayer = false;
	bStop = false;
	setHeadTailLen(-1, -1);
	m_pDatagram = new Datagram(-1);
}

bool CLayerInterface::init()
{
	if (m_nMsgHeadLen == -1 || m_nMsgTailLen == -1)
		return false;
	
	m_pDatagram->m_nMsgHeadLen = m_nMsgHeadLen;
	m_pDatagram->m_nMsgTailLen = m_nMsgTailLen;
	
	if (!bHasServerLayer)
		return true;
	else if (pServerLayer == NULL)
		return false;
	pServerLayer->init();
	return true;
}

CLayerInterface::~CLayerInterface()
{
	if (hThread)
		CloseHandle(hThread);
	if (pServerLayer)
		delete pServerLayer;
}

void CLayerInterface::setHeadTailLen(int iMsgHeadLen, int iMsgTailLen) {
	m_nMsgHeadLen = iMsgHeadLen;
	m_nMsgTailLen = iMsgTailLen;
}

void CLayerInterface::run()
{
	hThread = CreateThread(NULL, 0, layerThread, this, 0, NULL);
	if (pServerLayer != NULL)
	{
		pServerLayer->run();
	}
}


DWORD WINAPI CLayerInterface::layerThread(LPVOID lpParam){
	int id = GetCurrentThreadId();
	CLayerInterface *layer = static_cast<CLayerInterface *>(lpParam);
	while (!layer->bStop)
	{
		layer->sendTransfer();
		layer->recvTransfer();
		if (layer->myRecvBuf.empty() && layer->m_pClientSendBuf.empty())
			Sleep(100);
	}
	if (layer->pServerLayer != NULL)
	{
		layer->pServerLayer->bStop = true;
	}
	return 0;
}


void CLayerInterface::stopRun()
{
	bStop = false;
}

bool CLayerInterface::isBufferReady(int lable) {
	if (lable == CLIENT)
	{
		return (!m_pClientSendBuf.empty());
	}
	else {
		return (!myRecvBuf.empty());
	}
}

Datagram CLayerInterface::getData(int lable) {
	if (lable == CLIENT)
	{
		return m_pClientSendBuf.pop();
	}
	else {
		return myRecvBuf.pop();
	}
}

bool CLayerInterface::sendData(Datagram datagram) {
	bool ret = true;

	if (!bHasServerLayer)
		ret = false;
	else
		ret = mySendBuf.push(datagram);

	return ret;
}

bool CLayerInterface::recvData(Datagram datagram) {
	bool ret = true;
	ret = m_pClientRcvBuf.push(datagram);
	return ret;
}


void CLayerInterface::package(Datagram datagram){
	m_pDatagram->createBuf(datagram);
	addHead();
	addTail();
}


void CLayerInterface::unpack(){
	rmvHeadBuf();
}

void CLayerInterface::rmvHeadBuf() {
	m_pDatagram->m_nMsgHeadLen = m_nMsgHeadLen;
	m_pDatagram->m_nMsgTailLen = m_nMsgTailLen;
	m_pDatagram->rmvHeadBuf();
}

void CLayerInterface::recvTransfer()
{
	if (isBufferReady(SERVER))
	{
		*m_pDatagram = getData(SERVER);
		unpack();
		recvData(*m_pDatagram);
	}
}


void CLayerInterface::sendTransfer()
{
	if (isBufferReady(CLIENT))
	{
		Datagram datagram = getData(CLIENT);
		package(datagram);
		sendData(*m_pDatagram);
	}
}
