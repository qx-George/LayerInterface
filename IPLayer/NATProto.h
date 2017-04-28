#pragma once
#include <vector>
#include <utility>

// NAT 转换表
class CTransTable{

	std::vector<std::pair<std::string, std::string>> NatTable;
};


class CNATProto
{
public:
	CNATProto();
	~CNATProto();

	void convert(); // 地址转换查询

	CTransTable table;
};

