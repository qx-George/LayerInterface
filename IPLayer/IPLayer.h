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
	void routing();		// 调用路由

	void fragment();	// IP数据报分片
	void reassemble();	// IP数据报重组

protected:
	void addHead();

private:
	CDatagramCheck m_datagramCheck;
	enum m_routeProtoType
	{
		osfp
	};				// 用于标记路由协议类型
	CRouteProto *m_pRouteProto;

	bool isRoute;	// 标记是否是路由器， 路由器不运行在传输层， 需重写recvData
};
