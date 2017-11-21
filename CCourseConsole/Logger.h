#pragma once
#include "I_Logger.h"
class Logger :
	public I_Logger
{
	FILE *file;
public:
	Logger();

	void openResourse();
	void outputInfo(const char *str);
	void closeResourse();

	~Logger();
};

