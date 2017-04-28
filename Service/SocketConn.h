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
		CREATED = 0,	// ´´½¨
		CONNECT = 1,	// Á´½Ó
	};
};

