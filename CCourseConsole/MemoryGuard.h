#pragma once
#include <cstdlib>


class MemoryGuard
{
public:
	MemoryGuard(void *dynamicObj);
	~MemoryGuard();

	void * getSlot();

private:
	void *protD;
};

