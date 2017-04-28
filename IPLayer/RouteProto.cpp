#include "stdafx.h"
#include "RouteProto.h"


CRouteProto::CRouteProto(CIPLayer *pIPProto)
{
	m_pIPProto = pIPProto;
}


CRouteProto::~CRouteProto()
{
}

void CRouteProto::update()
{
	// 在此更新转发表
}
