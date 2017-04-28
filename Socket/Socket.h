#pragma once
#include <string>
#include "NetConn.h"
#include "MailSlot.h"

class CSocket
{
public:
	CSocket();
	/**
	* @brief	用于创建一个socket描述符，它唯一标识一个socket
	* @param[in] domain：即协议域，又称为协议族
	* @param[in] type：指定socket类型
	* @param[in] protocol：指定协议
	* @return	socket标识符
	*/
	int socket(int domain, int type, int protocol);

	/**
	* @brief	服务器绑定IP与端口号
	* @param[in] socketId : socket描述符
	* @param[in] IP：网络地址
	* @param[in] port：端口号
	* @return	错误码
	*/
	int bind(int socketId, std::string IP, unsigned short int port);

	/**
	* @brief	服务器端监听
	* @param[in] socketId : socket描述符
	* @param[in] linkSize : socket可以排队的最大连接个数
	* @return	错误码
	*/
	int listen(int socketId, int linkSize);

	/**
	* @brief	客户端请求链接IP与端口号
	* @param[in] socketId : socket描述符
	* @param[in] IP：网络地址
	* @param[in] port：端口号
	* @return	错误码
	*/
	int connect(int socketId, std::string IP, unsigned short int port);

	/**
	* @brief	服务器同意链接
	* @param[in] socketId : socket描述符
	* @param[in] IP：客户端网络地址
	* @param[in] port：客户端端口号
	* @return	socket描述符
	*/
	int accept(int socketId, std::string &IP, unsigned short int &port);

	/**
	* @brief 发送与接收
	*/
	int recv(int socketId, char * &msg, int &length);
	int send(int socketId, char * msg, int length);

	/**
	* @brief	关闭连接
	* @param[in] socketId : socket描述符
	* @return	socket描述符
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