#include "stdafx.h"
#include "Logger.h"
#include <conio.h>
#include <string.h>

Logger::Logger()
{
}

void Logger::openResourse()
{
	fopen_s(&file, "D:\\logfile", "ab");
	if (file == NULL)
		puts("logfile open error\n");
}

void Logger::outputInfo(const char * str)
{
	if (file != NULL)
	{
		fwrite(str, sizeof(char), strlen(str), file);
	}
	else
		puts("logfile write error\n");
}

void Logger::closeResourse()
{
	if (file != NULL)
	{
		fclose(file);
	}
	else
		puts("logfile close error\n");
}


Logger::~Logger()
{
	if (file != NULL)
		fclose(file);
}
