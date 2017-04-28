// DatagramCheck.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DatagramCheck.h"

// This is the constructor of a class that has been exported.
// see DatagramCheck.h for the class definition
CDatagramCheck::CDatagramCheck()
{
	return;
}


void CDatagramCheck::setPara(char *pHead, int ilength) {
	m_pMsgHead = pHead;
	m_iMsgLen = ilength;
}

int CDatagramCheck::check(int proto)
{
	switch (proto)
	{
	case CRC:
		return CRCcheck();
	default:
		return -1;
	}
}

int CDatagramCheck::CRCcheck()
{
	return -1;
}