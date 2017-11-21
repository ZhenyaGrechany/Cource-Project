#include "stdafx.h"
#include "Milit.h"
#include <iostream>
using namespace std;

Milit::Milit()
{
}

void Milit::printTime(int H, int M, int S)
{
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

	while (H>23)
	{

		H -= 24;
	}

	cout << H << ':' << M << ':' << S << ' ' << endl;
}

Milit::~Milit()
{
}
