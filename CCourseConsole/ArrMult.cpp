#include "stdafx.h"
#include "ArrMult.h"


ArrMult::ArrMult(int mult):multiplier(mult)
{
}


ArrMult::~ArrMult()
{
}

void ArrMult::Mult(int * pAr, int nSize)
{
	for  (int i = 0; i < nSize; i++)
	{
		pAr[i] *= multiplier;
	}
}
