#pragma once
#include "RouteProto.h"
class CRIPRouteProto :
	public CRouteProto
{
public:
	CRIPRouteProto(CIPLayer *pIPProto);
	~CRIPRouteProto();
};

