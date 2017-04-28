#pragma once
class CLinkLayer;

class CARPProto
{
public:
	CARPProto(CLinkLayer *pLinkLayer);
	~CARPProto();

private:
	CLinkLayer *m_pLinkLayer;
};

