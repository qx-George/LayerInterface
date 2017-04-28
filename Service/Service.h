// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SERVICE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SERVICE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SERVICE_EXPORTS
#define SERVICE_API __declspec(dllexport)
#else
#define SERVICE_API __declspec(dllimport)
#endif

#include <string>
#include <vector>
#include "SocketConn.h"

#include "../LayerInterface/LayerInterface.h"
#pragma comment(lib, "../Debug/LayerInterface.lib")
#pragma comment(lib, "../Debug/TransportLayer.lib")
class CTransportLayer;

// This class is exported from the Service.dll
class SERVICE_API CService {
public:
	CService(void);
	// TODO: add your methods here.

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
	int allocSocket(CNetConn *);

	//These buffers used by this layer and lower layer
	std::vector<MsgList> mySendBufVec;
	std::vector<MsgList> myRecvBufVec;

	CTransportLayer *tranLayer;
	std::vector<CSocketConn> sockets;
};

extern SERVICE_API int nService;

SERVICE_API int fnService(void);
