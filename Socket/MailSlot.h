#pragma once
#ifdef LAYERINTERFACE_EXPORTS
#define LAYERINTERFACE_API __declspec(dllexport)
#else
#define LAYERINTERFACE_API __declspec(dllimport)
#endif

/*****************************************
* @brief	通过邮件槽方式实现进程间通信
* @author	XF_Shaw
* @version	2017-03-13
******************************************/
#include <string>
#include "NetConn.h"
typedef void *HANDLE;

class  CMailSlot
{
public:
	CMailSlot();
	~CMailSlot();

	/**
	* @brief	创建邮件槽
	* @param[in] slotName	邮件槽名字
	* @param[in] socketId	socket号
	*/
	bool createMailSlot(int id);
	bool open(int id);
	bool close();
	// 读取数据
	bool read(CNetConn &conn);
	bool read(char *&msg, int &length);
	// 写入数据
	bool write(const CNetConn &conn);
	bool write(const char *msg, const int length);

	std::string lastErr;

private:
	HANDLE _hMailSlot;
	HANDLE _hFile;

	static std::string slotName;
};

