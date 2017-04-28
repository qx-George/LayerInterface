#pragma once
#include <string>
#include <list>
// 连接状态码
enum SEVER_STAT
{
	CLOSED = 0,
	LISTEN,
	SYN_RCVD,
	ESTABLISHED,
	CLOSE_WAIT,
	LAST_ACK
};

enum CLIENT_STAT
{
	CLOSED1 = 0,
	SYN_SENT,
	ESTABLISHED1 = 3,
	FIN_WAIT_1,
	FIN_WAIT_2,
	TIME_WAIT
};

// 链接表项，可根据需求添加元素
class Tuple
{
public:
	Tuple(std::string IP, unsigned int pt, int stat = 0)
		: IPAdress(IP), port(pt), state(stat) {}
	~Tuple(){}

public:
	std::string		IPAdress;	// IP地址
	unsigned int	port;		// 端口号
	int				state;		// 当前状态
};

//===========================================================
// Name				: LinkRegister
// Author			: XF_Shaw
// Version			: 2016-08-27
// Descripthion		: 此类记录了TCP连接的相关信息
//===========================================================
class LinkRegister
{
	typedef std::list<Tuple>::iterator Pointer;
public:
	LinkRegister();
	~LinkRegister();

	Pointer next();
	Pointer find(std::string IPAddress, int port);
	void insert(Tuple tuple);
	bool remove();
	bool isEmpty();
	void reset();
	void clear();
private:
	std::list<Tuple> reg;		// 保存所有链接
	Pointer cur;
};

