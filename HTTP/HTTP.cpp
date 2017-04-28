// HTTP.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "HTTP.h"
#include "../LayerInterface/Datagram.h"


// This is the constructor of a class that has been exported.
// see HTTP.h for the class definition
CHTTP::CHTTP(char *data , int length) {
	// �ϲ�����
	char *ndata = new char[length];
	memcpy(ndata, data, length);

	// �����ݷ�װ��ͳһ�����ݽṹ
	Datagram data1(length);
	//data1.cpyData(ndata);
	data1.pHead = ndata;
	sendList.push(data1);

	// �������Ƶ��²�
	tranLayer = new CUDP(sendList, rcvList);
	tranLayer->init();
	tranLayer->run();
}

char* CHTTP::getData() {
	Datagram data2;
	data2 = rcvList.pop();
	return data2.pData;
}

CHTTP::~CHTTP()
{
	delete tranLayer;
}