#pragma once
#include <vector>
#include <utility>

// NAT ת����
class CTransTable{

	std::vector<std::pair<std::string, std::string>> NatTable;
};


class CNATProto
{
public:
	CNATProto();
	~CNATProto();

	void convert(); // ��ַת����ѯ

	CTransTable table;
};

