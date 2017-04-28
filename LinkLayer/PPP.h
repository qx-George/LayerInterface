#pragma once

#pragma comment(lib, "../Debug/LayerInterface.lib")
#pragma comment(lib, "../Debug/DatagramCheck.lib")
#include "../LayerInterface/LayerInterface.h"
#include "../DatagramCheck/DatagramCheck.h"

class CPPP : public CLayerInterface
{
public:
	CPPP();
	~CPPP();

protected:
	void sendTransfer();
	void addTail();
	void addHead();
};

