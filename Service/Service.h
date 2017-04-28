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
	int allocSocket(CNetConn *);

	//These buffers used by this layer and lower layer
	std::vector<MsgList> mySendBufVec;
	std::vector<MsgList> myRecvBufVec;

	CTransportLayer *tranLayer;
	std::vector<CSocketConn> sockets;
};

extern SERVICE_API int nService;

SERVICE_API int fnService(void);
