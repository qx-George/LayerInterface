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
// Description : 用于协议栈之间信息交流的队列
// Attention   : 这里并未提供内存上限控制，你应该在TCP层的拥塞/流量控制方面做文章
//				 否则此处可能会产生内存溢出的异常。
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

