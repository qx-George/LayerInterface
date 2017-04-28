#pragma once
#ifdef LAYERINTERFACE_EXPORTS
#define LAYERINTERFACE_API __declspec(dllexport)
#else
#define LAYERINTERFACE_API __declspec(dllimport)
#endif

#include <string>

/**
* 记录链接状态信息
*/
class LAYERINTERFACE_API CNetConn
{
public:
	std::string lastErr;
	int socket;
	std::string srcIP, dstIP;
	unsigned int srcPort, dstPort;
	int tranProto;
	CNetConn *next;


	// 新建对象
	void alloc(int type, int proto);
	// 记录地址
	void setAddress(std::string IP, unsigned int port, int isRemote);

	static CNetConn *phead;		//记录头指针
};

