#include "stdafx.h"
#include "B.h"
#include "A.h"

B::B():mB(10)
{
	cout << "B constructor!!! " << this << endl;
}

B::~B()
{
	cout << "B destructor!!! " << this << endl;
}

void B::Func(A *pA)
{
	pA->ma += 10;

}

void B::showAA(A * pA)
{
	cout << pA->ma << endl;
	cout << pA->mbb.mB+pA->ma << endl;
}
