#pragma once
//====================================================================================
// Name        : Datagram
// Author      : XF_Shaw
// Version     : 2016/7/18
// Copyright   : 
// Description : �����洢���޸ı��Ķ�/���ݰ�/֡��Ϣ����
// Attantion   : ��Э��ջ���м�㣬�����Ѿ��ṩ�������ڴ��ת�����ͷŹ��ܡ��������д
//				 ������·���Ӧ�ò�ʱ����Ӧ��ע���Ƿ���Ҫ�����ڴ�������
//====================================================================================

class Datagram
{
public:
	char *pHead;			// ����ͷָ��
	char *pData;			// ��������ָ��
	char *pTail;			// ����βָ��
	int m_nMegLen;			// �����ܳ���
	int m_nMsgHeadLen;		// ����ͷ����
	int m_nMsgTailLen;		// ����β����

	Datagram() : Datagram(-1){ }

	/**
	* @brief	���ݱ��Ĺ��캯��
	* @param[in] iMsgLen	���ݱ�����
	*/
	Datagram(int iMsgLen) {
		pHead = nullptr;
		pData = nullptr;
		pTail = nullptr;
		m_nMegLen = iMsgLen;
		//pHead = new char[m_nMegLen];
	}

	/**
	* @brief	���ݱ��Ŀ���
	* @param[in] pData	���ݱ�ͷָ��
	*/
	void cpyData(char *pData);

	/**
	* @brief	���ݱ���ȥͷȥβ����
	* @attention	ע��˴�ֻ���޸ı����Ϣ����δ�����ڴ��Ǩ�����ͷŲ���
	*/
	void rmvHeadBuf();

	/**
	* @brief	���ݱ��Ĵ�������
	* @param[in] datagram	�ϲ����ݱ�
	*/
	void createBuf(Datagram datagram);

	/**
	* @brief	���ݱ����ͷ�
	*/
	void release();

	int getId();
	void setId(int id);
private:
	int id;
};