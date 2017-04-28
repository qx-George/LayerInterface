// LayerTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "../LayerInterface/Datagram.h"
#include "../LayerInterface/LayerBuffer.h"
#include "../HTTP/HTTP.h"
#include "../Service/Service.h"
#include "../LayerInterface/MailSlot.h"
#include "../TransportLayer/TransportLayer.h"
#pragma comment(lib, "../Debug/HTTP.lib")
#pragma comment(lib, "../Debug/Service.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	Datagram data1, data2;
	char s[] = "hello";
	/*
	CHTTP http(s, strlen(s)+1);
	getchar();
	char *test = http.getData();
	std::cout <<"�������н����" << test << std::endl;
	getchar();
	*/

	/*
	CService cs;
	int id = cs.socket(0, cs.DGRAM, cs.UDP);
	cs.send(id, s, strlen(s)+1);
	getchar();
	char *msg = nullptr; 
	int length;
	cs.recv(id, msg, length);
	std::cout << "���н���� "<< msg << std::endl;
	*/
	/*
	CMailSlot mailslot;
	mailslot.createMailSlot(0);
	char *msg;
	int length;
	while (mailslot.read(msg, length)) 
	{
		std::cout << length << std::endl;
		std::cout << msg << std::endl;
	}
	*/

	CTransportLayer trans;
	trans.init();
	trans.run();
	getchar();
	return 0;
}

