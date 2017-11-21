#pragma once
#include "I_Logger.h"
class CLogger :
	public I_Logger
{
	bool out;
public:
	CLogger();

	void openResourse();
	void outputInfo(const char *str);
	void closeResourse();

	~CLogger();
};

