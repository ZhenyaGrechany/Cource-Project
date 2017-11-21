#include "stdafx.h"
#include "Clock.h"


Clock::Clock(int i_H, int i_M, int i_S):H(i_H),M(i_M),S(i_S)
{
}

void Clock::setPrint(I_Time * time_f)
{
	time_m = time_f;
}

void Clock::print()
{
	time_m->printTime(H,M,S);
}


Clock::~Clock()
{
}
