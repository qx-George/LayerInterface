#ifdef HTTP_EXPORTS
#define HTTP_API __declspec(dllexport)
#else
#define HTTP_API __declspec(dllimport)
#endif
#pragma comment(lib, "../Debug/UDP.lib")
#include"../UDPLayer/CUDP.h"

// This class is exported from the HTTP.dll
class HTTP_API CHTTP{
public:
	CHTTP();
	CHTTP(char *data, int length);
	char* getData();
	~CHTTP();
	CUDP *tranLayer;
	MsgList sendList, rcvList;
};

