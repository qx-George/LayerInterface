#pragma once
#include "UDP.h"

class CTCP :
	public CUDP
{
public:
	CTCP(MsgList &sendBuf, MsgList &rcvBuf);
	~CTCP();
	bool connect();
	bool disconnect();
protected:
	void addHead();
};

