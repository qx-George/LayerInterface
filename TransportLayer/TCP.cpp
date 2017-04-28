#include "stdafx.h"
#include "TCP.h"


CTCP::CTCP(MsgList &sendBuf, MsgList &rcvBuf) : CUDP(sendBuf, rcvBuf)
{
	
}

CTCP::~CTCP()
{
}

void CTCP::addHead()
{
	char data[] = "TCP head --- ";
	memcpy(m_pDatagram->pHead, data, sizeof(data));

	// add check function ;
}


bool CTCP::connect()
{
	// ÔÚ´Ë´¦Íù
	return true;
}

bool CTCP::disconnect()
{
	return true;
}

