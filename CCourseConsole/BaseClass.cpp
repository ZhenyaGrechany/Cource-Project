#include "stdafx.h"
#include "BaseClass.h"


BaseClass::BaseClass(int inputData):data(inputData)
{
}


BaseClass::~BaseClass()
{
}

void BaseClass::setData(int input)
{
	data = input;
}

int BaseClass::getData()
{
	return data;
}
