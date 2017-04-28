#include "stdafx.h"
#include "Datagram.h"
#include <stdlib.h>

void Datagram::createBuf(Datagram datagram) {
	m_nMegLen = m_nMsgHeadLen + datagram.m_nMegLen + m_nMsgTailLen;	//更新报文长度
	pHead = new char[m_nMegLen];
	memset(pHead, 0, m_nMegLen);
	pData = pHead + m_nMsgHeadLen;
	pTail = pData + datagram.m_nMegLen;
	memcpy(pData, datagram.pHead, datagram.m_nMegLen);
	datagram.release();		// 释放上层报文
}

// 注意此处只是修改标记信息，并未进行内存的迁移与释放操作
void Datagram::rmvHeadBuf() {
	pData = pData + m_nMsgHeadLen;
	m_nMegLen = m_nMegLen - m_nMsgHeadLen - m_nMsgTailLen;
}


void Datagram::release() {
	delete[] pHead;
}


void Datagram::cpyData(char *pData) {
	memcpy(pHead, pData, m_nMegLen);
}

int Datagram::getId()
{
	return id;
}

void Datagram::setId(int id)
{
	this->id = id;
}