#pragma once
#include "IPLayer.h"

class CRouteProto
{
public:
	CRouteProto(CIPLayer *pIPProto);
	~CRouteProto();

	void update();	//������Ӧ�㷨������·��ѡ���


protected:
	CIPLayer *m_pIPProto;
};

