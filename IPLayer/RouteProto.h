#pragma once
#include "IPLayer.h"

class CRouteProto
{
public:
	CRouteProto(CIPLayer *pIPProto);
	~CRouteProto();

	void update();	//根据相应算法，更新路由选择表


protected:
	CIPLayer *m_pIPProto;
};

