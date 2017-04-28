#pragma once
#include <string>
#include "NetConn.h"
#include "MailSlot.h"

class CSocket
{
public:
	CSocket();
	/**
	* @brief	���ڴ���һ��socket����������Ψһ��ʶһ��socket
	* @param[in] domain����Э�����ֳ�ΪЭ����
	* @param[in] type��ָ��socket����
	* @param[in] protocol��ָ��Э��
	* @return	socket��ʶ��
	*/
	int socket(int domain, int type, int protocol);

	/**
	* @brief	��������IP��˿ں�
	* @param[in] socketId : socket������
	* @param[in] IP�������ַ
	* @param[in] port���˿ں�
	* @return	������
	*/
	int bind(int socketId, std::string IP, unsigned short int port);

	/**
	* @brief	�������˼���
	* @param[in] socketId : socket������
	* @param[in] linkSize : socket�����Ŷӵ�������Ӹ���
	* @return	������
	*/
	int listen(int socketId, int linkSize);

	/**
	* @brief	�ͻ�����������IP��˿ں�
	* @param[in] socketId : socket������
	* @param[in] IP�������ַ
	* @param[in] port���˿ں�
	* @return	������
	*/
	int connect(int socketId, std::string IP, unsigned short int port);

	/**
	* @brief	������ͬ������
	* @param[in] socketId : socket������
	* @param[in] IP���ͻ��������ַ
	* @param[in] port���ͻ��˶˿ں�
	* @return	socket������
	*/
	int accept(int socketId, std::string &IP, unsigned short int &port);

	/**
	* @brief ���������
	*/
	int recv(int socketId, char * &msg, int &length);
	int send(int socketId, char * msg, int length);

	/**
	* @brief	�ر�����
	* @param[in] socketId : socket������
	* @return	socket������
	*/
	int close(int socketId);

	/* Socket protocol types (TCP/UDP/RAW) */

	enum SOCK_PROTO
	{
		STREAM = 1,
		DGRAM = 2,
		RAW = 3
	};

	enum Proto
	{
		TCP, UDP
	};

private:
	CNetConn conn;
	CMailSlot _mailSlot, _linkSlot;
};