#ifdef UDPLAYER_EXPORTS
#define UDPLAYER_API __declspec(dllexport)
#else
#define UDPLAYER_API __declspec(dllimport)
#endif

#pragma comment(lib, "../Debug/LayerInterface.lib")
#include "../LayerInterface/LayerInterface.h"
#include <vector>

class UDPLAYER_API CUDP : public CLayerInterface{
public:
	CUDP(MsgList &sendBuf, MsgList &rcvBuf);
	bool init();
	~CUDP();
	void addClient(MsgList sendBuf, MsgList rcvBuf);

protected:
	void addHead();

	std::vector<MsgList*> m_MsgListSendQue;
	int m_iSendQueTail;
	std::vector<MsgList*> m_MsgListRecvQue;
	int m_iRecvQueTail;
};
