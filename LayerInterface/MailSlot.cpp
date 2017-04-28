#include "stdafx.h"
#include "MailSlot.h"
#include <windows.h>
#include "NetConn.h"
using namespace::std;

LPCWSTR stringToLPCWSTR(std::string orig)
{
	size_t origsize = orig.length() + 1;
	size_t convertedChars = 0;
	wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(orig.length() - 1));
	mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);
	return wcstring;
}

string CMailSlot::slotName = "\\\\.\\mailslot\\mailslot";

CMailSlot::CMailSlot()
{
}


CMailSlot::~CMailSlot()
{
	CloseHandle(_hMailSlot);
}

bool CMailSlot::createMailSlot(int id)
{
	_hMailSlot = CreateMailslot(stringToLPCWSTR(slotName + to_string(id)), 0, 100, NULL);
	if (_hMailSlot == INVALID_HANDLE_VALUE)
	{
		lastErr = "CreateMailslot failed!" + GetLastError();
		return false;
	}
	return true;
}


bool CMailSlot::open(int id)
{
	_hFile = CreateFile(stringToLPCWSTR(slotName + to_string(id)), GENERIC_WRITE,
		FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (_hFile == INVALID_HANDLE_VALUE)
	{
		lastErr = "CreateFile failed!" + GetLastError();
		return false;
	}
	return true;
}


bool CMailSlot::close()
{
	return CloseHandle(_hFile);
}

bool CMailSlot::read(CNetConn &conn)
{
	DWORD NumberOfBytesRead;
	if (0 != ReadFile(_hMailSlot, &conn, sizeof(CNetConn), &NumberOfBytesRead, NULL))
	{
		return true;
	}
	return false;
}

bool CMailSlot::read(char *&msg, int &length)
{
	DWORD NumberOfBytesRead;
	char *temp = new char[1024];
	memset(temp, 0, 1024 * sizeof(char));
	if (0 != ReadFile(_hMailSlot, temp, 1024, &NumberOfBytesRead, NULL))
	{
		length = NumberOfBytesRead;
		msg = new char[length];
		memcpy(msg, temp, length);
		delete temp;
		return true;
	}
	delete temp;
	return false;
}


bool CMailSlot::write(const CNetConn &conn)
{
	DWORD BytesWritten;
	if (0 == WriteFile(_hFile, &conn, sizeof(CNetConn), &BytesWritten, NULL))
	{
		lastErr = "WriteFile failed!" + GetLastError();
		return false;
	}
	return true;
}


bool CMailSlot::write(const char *msg,  const int length)
{
	DWORD BytesWritten;
	if (0 == WriteFile(_hFile, msg, length, &BytesWritten, NULL))
	{
		lastErr = "WriteFile failed!" + GetLastError();
		return false;
	}
	return true;
}