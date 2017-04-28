#pragma once
#pragma comment(lib, "../Debug/LayerInterface.lib")
#include "../LayerInterface/LayerInterface.h"
class CTransportLayer;

class CUDP :
	public CLayerInterface
{
public:
	CUDP(MsgList &sendBuf, MsgList &rcvBuf);
	~CUDP();
	bool isBufferReady(int lable);
	bool sendData(Datagram datagram);
	Datagram getData(int lable);

	CTransportLayer *outerLayer;
protected:
	void addHead();
};

