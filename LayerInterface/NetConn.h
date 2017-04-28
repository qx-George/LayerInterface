#pragma once
#ifdef LAYERINTERFACE_EXPORTS
#define LAYERINTERFACE_API __declspec(dllexport)
#else
#define LAYERINTERFACE_API __declspec(dllimport)
#endif

#include <string>

/**
* ��¼����״̬��Ϣ
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


	// �½�����
	void alloc(int type, int proto);
	// ��¼��ַ
	void setAddress(std::string IP, unsigned int port, int isRemote);

	static CNetConn *phead;		//��¼ͷָ��
};

