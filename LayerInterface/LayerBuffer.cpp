#include "stdafx.h"
#include "LayerBuffer.h"


MsgList::MsgList()
{
}

MsgList::~MsgList()
{
}


bool MsgList::push(Datagram data)
{
	bool ret = true;
	_mLock.lock();
	// write to Tail
	try {
		buffer.push_back(data);
	}
	catch (...) {
		ret = false;
	}
	_mLock.unLock();
	return ret;
}

Datagram MsgList::pop()
{
	Datagram ret;
	_mLock.lock();
	// read from front
	ret = buffer.front();
	buffer.erase(buffer.begin());
	_mLock.unLock();

	return ret;
}


bool MsgList::empty()
{
	_mLock.lock();
	bool isEmpty = buffer.empty();
	_mLock.unLock();
	return isEmpty;
}

