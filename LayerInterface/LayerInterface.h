#pragma once
#ifdef LAYERINTERFACE_EXPORTS
#define LAYERINTERFACE_API __declspec(dllexport)
#else
#define LAYERINTERFACE_API __declspec(dllimport)
#endif

//==================================================================================
// Name        : LayerInterface
// Author      : XF_Shaw
// Version     : 2016/7/18
// Copyright   : 
// Description : 这个类是所有网络层的基类，已经封装了上下层之间的数据通信。
//				 你只需要继承此类，将重点放在网络各层功能的实现上即可。
//===================================================================================
#include "Datagram.h"
#include "LayerBuffer.h"
class CNetConn;
// This class is exported from the LayerInterface.dll
class LAYERINTERFACE_API CLayerInterface {
public:
	CLayerInterface();
	CLayerInterface(MsgList &td, MsgList &dt);
	virtual ~CLayerInterface();

	bool init();
	void run();
	void stopRun();
	static DWORD WINAPI layerThread(LPVOID lpParam);
	void layerControl();
	virtual bool isBufferReady(int lable);			//check if the buffer can be used
	virtual Datagram getData(int lable);			//get data from the buffer
	virtual bool sendData(Datagram data);			//insert the data into buffer
	virtual bool recvData(Datagram data);
	void setHeadTailLen(int iMsgHeadLen, int iMsgTailLen);
	// CNetConn *conn;
protected:
	virtual void package(Datagram datagram);
	virtual void unpack();
	virtual void addHead() {}
	virtual void addTail() {}
	void rmvHeadBuf();
	virtual void sendTransfer();
	virtual void recvTransfer();


protected:
	enum { SERVER = 0, CLIENT };			//sent_layer:client   recieve_layer:server
	bool bStop;
	CLayerInterface *pServerLayer;
	bool bHasServerLayer;
	Datagram *m_pDatagram;

	int m_nMsgHeadLen;
	int m_nMsgTailLen;

	//These buffers used by this layer and lower layer
	MsgList mySendBuf;			//top->down buffer
	MsgList myRecvBuf;			//down->top buffer
	//inherite from the upper layer
	MsgList &m_pClientSendBuf;
	MsgList &m_pClientRcvBuf;
	HANDLE hThread;
	
	enum m_ServProtoType
	{
		TCP, UDP, IP
	};				// 用于标记下层生成的协议类型
};
