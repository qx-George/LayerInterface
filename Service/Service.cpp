// Service.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Service.h"
#include "../LayerInterface/NetConn.h"
#include "../TransportLayer/TransportLayer.h"
#include "../LayerInterface/Datagram.h"
#include <iostream>

// This is an example of an exported variable
SERVICE_API int nService = 0;

// This is an example of an exported function.
SERVICE_API int fnService(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see Service.h for the class definition
CService::CService()
{
	//tranLayer = new CTransportLayer(mySendBufVec, myRecvBufVec);
	tranLayer->init();
	tranLayer->run();
}


int CService::socket(int domain, int type, int protocol)
{
	CNetConn *conn  = new CNetConn;
	switch (type)
	{
	case DGRAM:
		conn->alloc(type, protocol);
		// CNetConn * p = CNetConn::phead;
		int socketId = allocSocket(conn);
		conn->socket = socketId;
		
		return socketId;
	
	}
		return -1;		//-1 出错
}

int CService::allocSocket(CNetConn *conn)
{
	CSocketConn socketConn;
	for (size_t i = 0; i < sockets.size(); i++)
	{
		if (sockets[i].conn == nullptr)
		{
			// 在此处初始化socket列表
			socketConn.conn = conn;
			socketConn.state = socketConn.CREATED;
			return i;
		}
	}
	// 如果socket分配内存不够，在这里添加，并返回下标
	socketConn.conn = conn;
	socketConn.state = socketConn.CREATED;
	sockets.push_back(socketConn);
	return sockets.size() - 1;
}


int CService::bind(int socketId, std::string IP, unsigned short int port){
	// 在此处更新SocketConn的信息
	return -1;
}

int CService::connect(int socketId, std::string IP, unsigned short int port){
	// 在此处更新SocketConn的信息
	// 注册链接事件
	// 调用TCP三次握手
	CSocketConn socketConn = sockets[socketId];
	socketConn.state = CSocketConn::CONNECT;
	socketConn.conn->setAddress(IP, port, 1);
	tranLayer->connect();
	return -1;
}

int CService::listen(int socketId, int linkSize){
	// 在此线程轮询 调用
	return -1;
}

int CService::accept(int socketId, std::string &IP, unsigned short int &port){
	// 调用TCP三次握手
	return -1;
}

int CService::recv(int socketId, char * &msg, int &length) {
	// 从datagram队列内取数据
	Datagram data = myRecvBufVec[socketId].pop();
	length = data.m_nMegLen;
	msg = new char[length];
	memcpy(msg, data.pData, length);
	delete[] data.pHead;
	return 1;
}

int CService::send(int socketId, char * msg, int length) {
	// 在此打包为datagram，并放入发送队列
	if (socketId >= mySendBufVec.size())
	{
		mySendBufVec.resize(socketId + 1);
		myRecvBufVec.resize(socketId + 1);
	}


	// 上层数据
	char *ndata = new char[length];
	memcpy(ndata, msg, length);

	// 将数据封装入统一的数据结构
	Datagram data1(length);
	//data1.cpyData(ndata);
	data1.pHead = ndata;


	mySendBufVec[socketId].push(data1);
	return 1;
}

int CService::close(int socketId) {
	// 挥手
	// 清空相应缓冲区
	return -1;
}