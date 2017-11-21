#include "stdafx.h"
#include "CLogger.h"
#include <iostream>
using namespace std;


CLogger::CLogger()
{
}

void CLogger::openResourse()
{
	out = true;
}

void CLogger::outputInfo(const char * str)
{
	if(out == true)	cout << str;
	else puts("out error");
}

void CLogger::closeResourse()
{
	out = false;
}


CLogger::~CLogger()
{
}
