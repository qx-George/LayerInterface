#pragma once
#define LAYERBUFFER_EXPORTS
#ifdef LAYERBUFFER_EXPORTS
#define LAYERBUFFER_API __declspec(dllexport)
#else
#define LAYERBUFFER_API __declspec(dllimport)
#endif
//============================================================================
// Name        : LayerBuffer
// Author      : XF_Shaw
// Version     : 2016/7/18
// Copyright   : 
// Description : ����Э��ջ֮����Ϣ�����Ķ���
// Attention   : ���ﲢδ�ṩ�ڴ����޿��ƣ���Ӧ����TCP���ӵ��/�������Ʒ���������
//				 ����˴����ܻ�����ڴ�������쳣��
//============================================================================
#include "Datagram.h"
#include "MutexLock.h"
#include <vector>

class LAYERBUFFER_API MsgList
{
public:
	MsgList();
	~MsgList();

	bool empty();
	bool full();

	bool push(Datagram data);
	Datagram pop();
private:
	std::vector<Datagram> buffer;
	MutexLock _mLock;				//Mutex Lock
};

