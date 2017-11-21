#include "stdafx.h"
#include "MemoryGuard.h"




MemoryGuard::MemoryGuard(void * obj):
	protD(obj)
{
}

MemoryGuard::~MemoryGuard()
{
	if (protD != NULL)
		delete protD;
}

void * MemoryGuard::getSlot()
{
	return protD;
}