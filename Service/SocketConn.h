#pragma once
class CNetConn;
class CSocketConn
{
public:
	CSocketConn();
	~CSocketConn();

	CNetConn *conn;
	int state;

	enum SocketState
	{
		CREATED = 0,	// ����
		CONNECT = 1,	// ����
	};
};

