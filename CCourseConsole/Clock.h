#pragma once
#include "I_Time.h"

class Clock
{
	I_Time *time_m;
	int H, M, S;
public:
	Clock(int i_H,int i_M,int i_S);

	void setPrint(I_Time *time_f);
	void print();

	~Clock();
};

