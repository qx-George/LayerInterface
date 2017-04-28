#ifdef TCPLAYER_EXPORTS
#define TCPLAYER_API __declspec(dllexport)
#else
#define TCPLAYER_API __declspec(dllimport)
#endif

#pragma comment(lib, "../Debug/LayerInterface.lib")
#include "../LayerInterface/LayerInterface.h"
#include "../TCPLayer/TCPConnect.h"
#include "../TCPLayer/RDTransfer.h"
class TCPLAYER_API CTCP : public CLayerInterface{
public:
	CTCP(MsgList &sendBuf, MsgList &rcvBuf);
	~CTCP();

	bool connect(char *ip, int port);
	bool close(char *ip, int port);
	
	bool sendData(Datagram data);
	bool recvData(Datagram data);
protected:
	void addHead();

private:
	CTCPConnect m_TCPConnect;
	CRDTransfer *m_pRDTransfer;
};
