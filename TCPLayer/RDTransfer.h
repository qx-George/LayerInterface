#pragma once
#include "../LayerInterface/LayerInterface.h"
class CRDTransfer
{
public:
	CRDTransfer();
	~CRDTransfer();

	void send(char *pDatagram);
	void recieve();
	void setACK();

	char *m_pDatagram;	// ����
	CLayerInterface *m_pCTCP;
};

