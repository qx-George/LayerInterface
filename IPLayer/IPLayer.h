#ifdef IPLAYER_EXPORTS
#define IPLAYER_API __declspec(dllexport)
#else
#define IPLAYER_API __declspec(dllimport)
#endif
#pragma comment(lib, "../Debug/LayerInterface.lib")
#pragma comment(lib, "../Debug/DatagramCheck.lib")
#include "../LayerInterface/LayerInterface.h"
#include "../DatagramCheck/DatagramCheck.h"
class CRouteProto;


class IPLAYER_API CIPLayer : public CLayerInterface{
public:
public:
	CIPLayer(MsgList &sendBuf, MsgList &rcvBuf);
	~CIPLayer();
	void routing();		// ����·��

	void fragment();	// IP���ݱ���Ƭ
	void reassemble();	// IP���ݱ�����

protected:
	void addHead();

private:
	CDatagramCheck m_datagramCheck;
	enum m_routeProtoType
	{
		osfp
	};				// ���ڱ��·��Э������
	CRouteProto *m_pRouteProto;

	bool isRoute;	// ����Ƿ���·������ ·�����������ڴ���㣬 ����дrecvData
};
