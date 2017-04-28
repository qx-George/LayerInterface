#pragma once
#ifdef LAYERINTERFACE_EXPORTS
#define LAYERINTERFACE_API __declspec(dllexport)
#else
#define LAYERINTERFACE_API __declspec(dllimport)
#endif

/*****************************************
* @brief	ͨ���ʼ��۷�ʽʵ�ֽ��̼�ͨ��
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
	* @brief	�����ʼ���
	* @param[in] slotName	�ʼ�������
	* @param[in] socketId	socket��
	*/
	bool createMailSlot(int id);
	bool open(int id);
	bool close();
	// ��ȡ����
	bool read(CNetConn &conn);
	bool read(char *&msg, int &length);
	// д������
	bool write(const CNetConn &conn);
	bool write(const char *msg, const int length);

	std::string lastErr;

private:
	HANDLE _hMailSlot;
	HANDLE _hFile;

	static std::string slotName;
};

