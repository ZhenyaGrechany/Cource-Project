#include "stdafx.h"
#include "A.h"

A::A(int a) :ma(a)
{
	cout << "A constructor!!! " << this << endl;
}

A::~A()
{
	cout << "A destructor!!! " << this << endl;
}

