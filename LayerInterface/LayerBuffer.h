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

/**
 * @author��Xiong_Joe
 * @date��2017/4/30
 * @brief: �����������Э��ջ֮�佻����Ϣ�Ķ��У������֮�䴫����Ϣ��ͨ���˶�������ɣ�
 * �ܶԸö��н��еĲ������жϿպ�����������з������ݣ���ӣ����ʹӶ�����ȡ�����ݣ����ӣ�
 */
#include "Datagram.h"
#include "MutexLock.h"
#include <vector>

class LAYERBUFFER_API MsgList
{
public:
	MsgList();
	~MsgList();

	bool empty();     /**< ��������Ƿ�Ϊ��*/
	bool full();      /**< ��������Ƿ�Ϊ��*/

	bool push(Datagram data);    /**< �򻺳�����з�������*/
	Datagram pop();     /**< �ӻ��������ȡ������*/
private:
	std::vector<Datagram> buffer;   /**< ��Ϣ������У�ͨ��C++�Դ���������ʵ��*/
	MutexLock _mLock;				//Mutex Lock �������ٽ���Դ��������
};

