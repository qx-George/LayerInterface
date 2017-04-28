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
		return -1;		//-1 ����
}

int CService::allocSocket(CNetConn *conn)
{
	CSocketConn socketConn;
	for (size_t i = 0; i < sockets.size(); i++)
	{
		if (sockets[i].conn == nullptr)
		{
			// �ڴ˴���ʼ��socket�б�
			socketConn.conn = conn;
			socketConn.state = socketConn.CREATED;
			return i;
		}
	}
	// ���socket�����ڴ治������������ӣ��������±�
	socketConn.conn = conn;
	socketConn.state = socketConn.CREATED;
	sockets.push_back(socketConn);
	return sockets.size() - 1;
}


int CService::bind(int socketId, std::string IP, unsigned short int port){
	// �ڴ˴�����SocketConn����Ϣ
	return -1;
}

int CService::connect(int socketId, std::string IP, unsigned short int port){
	// �ڴ˴�����SocketConn����Ϣ
	// ע�������¼�
	// ����TCP��������
	CSocketConn socketConn = sockets[socketId];
	socketConn.state = CSocketConn::CONNECT;
	socketConn.conn->setAddress(IP, port, 1);
	tranLayer->connect();
	return -1;
}

int CService::listen(int socketId, int linkSize){
	// �ڴ��߳���ѯ ����
	return -1;
}

int CService::accept(int socketId, std::string &IP, unsigned short int &port){
	// ����TCP��������
	return -1;
}

int CService::recv(int socketId, char * &msg, int &length) {
	// ��datagram������ȡ����
	Datagram data = myRecvBufVec[socketId].pop();
	length = data.m_nMegLen;
	msg = new char[length];
	memcpy(msg, data.pData, length);
	delete[] data.pHead;
	return 1;
}

int CService::send(int socketId, char * msg, int length) {
	// �ڴ˴��Ϊdatagram�������뷢�Ͷ���
	if (socketId >= mySendBufVec.size())
	{
		mySendBufVec.resize(socketId + 1);
		myRecvBufVec.resize(socketId + 1);
	}


	// �ϲ�����
	char *ndata = new char[length];
	memcpy(ndata, msg, length);

	// �����ݷ�װ��ͳһ�����ݽṹ
	Datagram data1(length);
	//data1.cpyData(ndata);
	data1.pHead = ndata;


	mySendBufVec[socketId].push(data1);
	return 1;
}

int CService::close(int socketId) {
	// ����
	// �����Ӧ������
	return -1;
}