#pragma once
#include "I_Time.h"
class Milit :
	public I_Time
{
public:
	Milit();

	void printTime(int H, int M, int S);

	~Milit();
};

