#pragma once
class MsgList;
#include <vector>
#include "../LayerInterface/Datagram.h"

class CWindow{
public:
	std::vector<Datagram> wind;

	int size;
	int base;
	int nextseqnum;
};

class CRetransmission
{
public:
	CRetransmission();
	~CRetransmission();

	virtual void send();
	virtual void recv();
private:
	MsgList *sendList;	// 发送队列
	MsgList *rcevList;	// 接收队列
};

