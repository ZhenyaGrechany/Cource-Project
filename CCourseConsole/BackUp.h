#pragma once
#include <iostream>
#include "MemoryGuard.h"
#include <cstdlib>
#include "MemoryCheck.h"

using namespace std;


class BackUp
{
public:
	BackUp();
	~BackUp();

	int Write(const char* sFileName,void *pData,int nBytes);

	void * Read(const char* sFileName, int *pReadedBytes, int *pErrorCode);

private:

};

