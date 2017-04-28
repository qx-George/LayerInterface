// Socket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Socket.h"
#include <iostream>


CSocket::CSocket()
{

}

int CSocket::socket(int domain, int type, int protocol)
{
	switch (type)
	{
	case DGRAM:
		conn.tranProto = protocol;
		// int socketId = getpid();
		int socketId = 111;
		conn.socket = socketId;
		return socketId;
		
	}
	return -1;		//-1 ����
}


int CSocket::bind(int socketId, std::string IP, unsigned short int port){
	// �ڴ˴�����SocketConn����Ϣ
	if (_mailSlot.createMailSlot(port))
	{
		conn.srcIP = IP;
		conn.srcPort = port;
		return 1;
	}
	
	return -1;
}

int CSocket::connect(int socketId, std::string IP, unsigned short int port){
	// �ڴ˴�����SocketConn����Ϣ
	if (_mailSlot.open(0) && _linkSlot.open(1)){
		conn.dstIP = IP;
		conn.dstPort = port;
		bool isConnect = _linkSlot.write(conn);
		return 1;
	}		
	return -1;
}

int CSocket::listen(int socketId, int linkSize){
	// �ڴ��߳���ѯ ����
	return -1;
}

int CSocket::accept(int socketId, std::string &IP, unsigned short int &port){
	// ����TCP��������
	return -1;
}

int CSocket::recv(int socketId, char * &msg, int &length) {
	if (_mailSlot.read(msg, length))
	{
		return 1;
	}
	return -1;
}

int CSocket::send(int socketId, char * msg, int length) {
	if (_mailSlot.write(msg, length))
	{
		return 1;
	}
	return -1;
}

int CSocket::close(int socketId) {
	// ����
	// �����Ӧ������
	_mailSlot.close();
	return -1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	getchar();
	while(true){
	CSocket cs;
	int id = cs.socket(1, 1, 1);
	cs.bind(id, "1", 8080);
	cs.connect(id, "1", 10);
	char msg[] = "Hello";
	int length = sizeof(msg);
	bool write = cs.send(id, msg, length);
	cs.close(id);
	
	char *ans;
	int len;
	while (-1 == cs.recv(id, ans,len))
	{
		
	}
	std::cout << len << "\t" << ans << std::endl;
	getchar();
	}

	
	return 0;
}

