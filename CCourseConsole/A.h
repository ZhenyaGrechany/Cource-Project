#pragma once
#include "B.h"


class A
{
private:
	int ma;
	B mbb;
public:

	A(int a);
	~A();

	friend void B::Func(A *pA);
	friend void B::showAA(A *pA);

	

};
