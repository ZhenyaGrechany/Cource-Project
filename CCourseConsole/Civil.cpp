#include "stdafx.h"
#include "Civil.h"
#include <iostream>
using namespace std;

Civil::Civil()
{
}

void Civil::printTime(int H, int M, int S)
{
	bool AM = true;
	const char *st = "AM";
	while (S>59)
	{
		M++;
		S -= 60;
	}
	while (M>59)
	{
		H++;
		M -= 60;
	}

	while (H>11)
	{
		if (AM)
		{
			st = "PM";
			AM = false;
		}
		else
		{
			st = "AM";
			AM = true;
		}

		H -= 12;
	}

	cout << H << ':' << M << ':' << S << ' ' << st << endl;
}


Civil::~Civil()
{
}
