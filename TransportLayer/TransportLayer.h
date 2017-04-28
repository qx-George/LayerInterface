#ifdef TRANSPORTLAYER_EXPORTS
#define TRANSPORTLAYER_API __declspec(dllexport)
#else
#define TRANSPORTLAYER_API __declspec(dllimport)
#endif

#pragma comment(lib, "../Debug/LayerInterface.lib")
#include "../LayerInterface/LayerInterface.h"
#include <vector>
#include "../LayerInterface/MailSlot.h"
class CTCP;
class CUDP;

// This class is exported from the TransportLayer.dll
class TRANSPORTLAYER_API CTransportLayer : public CLayerInterface{
public:
	CTransportLayer(void);
	//CTransportLayer(std::vector<MsgList> &sendBufVec, std::vector<MsgList> &recvBufVec);
	bool init();
	void run();
	void sendTransfer();
	void recvTransfer();
	Datagram getData(int lable);
	Datagram getDatagram();				// 从队列取报文
	bool isRecvBufEmpty();
	bool isBufferReady(int lable);
	int connect();
	int disconnect();
	void multiplex();
	void demultiplex();
	void multiplex(Datagram data);		// 分发
	void demultiplex(Datagram data);	// 复用
private:
///	std::vector<MsgList> &pClientSendBuf;
///	std::vector<MsgList> &pClientRcvBuf;
	int index;
	MsgList udpSendBuf;
	MsgList recvBuf;
	MsgList tcpSendBuf;
	
	CUDP *udp;
	CTCP *tcp;
	CNetConn conn;
	CMailSlot mailslot,linkslot;
};

extern TRANSPORTLAYER_API int nTransportLayer;

TRANSPORTLAYER_API int fnTransportLayer(void);
