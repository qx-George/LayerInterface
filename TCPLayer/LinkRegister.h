#pragma once
#include <string>
#include <list>
// ����״̬��
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

// ���ӱ���ɸ����������Ԫ��
class Tuple
{
public:
	Tuple(std::string IP, unsigned int pt, int stat = 0)
		: IPAdress(IP), port(pt), state(stat) {}
	~Tuple(){}

public:
	std::string		IPAdress;	// IP��ַ
	unsigned int	port;		// �˿ں�
	int				state;		// ��ǰ״̬
};

//===========================================================
// Name				: LinkRegister
// Author			: XF_Shaw
// Version			: 2016-08-27
// Descripthion		: �����¼��TCP���ӵ������Ϣ
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
	std::list<Tuple> reg;		// ������������
	Pointer cur;
};

