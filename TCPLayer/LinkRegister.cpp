#include "stdafx.h"
#include "LinkRegister.h"
#include <algorithm>

LinkRegister::LinkRegister()
{
	cur = reg.begin();
}


LinkRegister::~LinkRegister()
{
}

bool LinkRegister::isEmpty() {
	return reg.empty();
}

void LinkRegister::clear() {
	reg.clear();
}

void LinkRegister::reset() {
	cur = reg.begin();
}

void LinkRegister::insert(Tuple tuple) {
	reg.push_back(tuple);
}

bool LinkRegister::remove() {
	if (cur == reg.end())
		return false;
	cur = reg.erase(cur);
	return true;
}

LinkRegister::Pointer LinkRegister::next() {
	if (reg.empty())
		return cur;
	if (cur == reg.end())
		reset();
	return cur++;
}

LinkRegister::Pointer LinkRegister::find(std::string IP, int port) {
	auto itr = std::find_if(reg.begin(), reg.end(),
		[IP, port](const Tuple &p) { 
		if (p.IPAdress == IP && p.port == port) 
			return true; 
		return false; });
	return itr;
}