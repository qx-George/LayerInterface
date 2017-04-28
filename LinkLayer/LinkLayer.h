#ifdef LINKLAYER_EXPORTS
#define LINKLAYER_API __declspec(dllexport)
#else
#define LINKLAYER_API __declspec(dllimport)
#endif
#pragma comment(lib, "../Debug/LayerInterface.lib")
#pragma comment(lib, "../Debug/DatagramCheck.lib")
#include "../LayerInterface/LayerInterface.h"
#include "../DatagramCheck/DatagramCheck.h"
#include "ARPProto.h"
class LINKLAYER_API CLinkLayer : public CLayerInterface{
public:
	CLinkLayer(MsgList &sendBuf, MsgList &rcvBuf);
	~CLinkLayer();
protected:
	void sendTransfer();
	void addTail();
	void addHead();

private:
	CDatagramCheck m_datagramCheck;
	CARPProto m_ARPProto;
};
