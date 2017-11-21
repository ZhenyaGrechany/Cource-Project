#include "stdafx.h"
#include "SingleLoger.h"
#include <string>

void SingleLoger::logOut(const char * str)
{
	FILE *fl;
	fopen_s(&fl,"D:\\logfile","ab");
	if (fl != NULL)
	{
		fwrite(str, sizeof(char), strlen(str), fl);
		fclose(fl);
	}
	else
		puts("logfile open error\n");
}

SingleLoger & SingleLoger::getInstance()
{
	static SingleLoger loger;
	return loger;
}

