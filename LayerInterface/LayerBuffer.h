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

/**
 * @author：Xiong_Joe
 * @date：2017/4/30
 * @brief: 这个类是用于协议栈之间交流信息的队列，层与层之间传递信息就通过此队列来完成，
 * 能对该队列进行的操作有判断空和满，向队列中发送数据（入队），和从队列中取出数据（出队）
 */
#include "Datagram.h"
#include "MutexLock.h"
#include <vector>

class LAYERBUFFER_API MsgList
{
public:
	MsgList();
	~MsgList();

	bool empty();     /**< 缓冲队列是否为空*/
	bool full();      /**< 缓冲队列是否为满*/

	bool push(Datagram data);    /**< 向缓冲队列中发送数据*/
	Datagram pop();     /**< 从缓冲队列中取出数据*/
private:
	std::vector<Datagram> buffer;   /**< 消息缓冲队列：通过C++自带的容器来实现*/
	MutexLock _mLock;				//Mutex Lock 用来对临界资源进行锁定
};

