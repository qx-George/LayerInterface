#pragma once
#include "RouteProto.h"
class CIPLayer;

class COSFPRouteProto :
	public CRouteProto
{
public:
	COSFPRouteProto(CIPLayer *pIPProto);
	~COSFPRouteProto();
};

