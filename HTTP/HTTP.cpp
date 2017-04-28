// HTTP.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "HTTP.h"
#include "../LayerInterface/Datagram.h"


// This is the constructor of a class that has been exported.
// see HTTP.h for the class definition
CHTTP::CHTTP(char *data , int length) {
	// 上层数据
	char *ndata = new char[length];
	memcpy(ndata, data, length);

	// 将数据封装入统一的数据结构
	Datagram data1(length);
	//data1.cpyData(ndata);
	data1.pHead = ndata;
	sendList.push(data1);

	// 将数据推到下层
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