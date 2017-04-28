#include "stdafx.h"
#include "NetConn.h"

CNetConn *CNetConn::phead = nullptr;

void CNetConn::alloc(int type, int proto)
{
	// ����ͷ��
	this->next = phead;
	phead = this;
	this->tranProto = proto;
}

void CNetConn::setAddress(std::string IP, unsigned int port, int isRemote)
{
	if (isRemote)
	{
		srcIP = IP;
		srcPort = port;
	}
	else
	{
		dstIP = IP;
		dstPort = port;
	}
}