#pragma once
#include "I_Time.h"
class Civil :
	public I_Time
{
public:
	Civil();

	void printTime(int H,int M,int S);

	~Civil();
};

