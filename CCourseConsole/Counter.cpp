#include "stdafx.h"
#include "Counter.h"


Counter::Counter(int inputCount):count(inputCount)
{
	//cout << "Counter constructor!!! " << this << endl;
}

Counter::Counter(const Counter &C):
	count(C.count)
{
	cout << "Counter  copy!!! " << this << " from " << &C << endl;
}

Counter::~Counter()
{
	//cout << "Counter destructor!! " << this << endl;
}

Counter Counter::operator+(const Counter & R)
{
	Counter Temp(count + R.count);

	cout << this  << '('<< count <<')'<< " + " << &R << '(' << R.count << ')'<< " = " << &Temp << '(' << Temp.count << ')' << endl;

	return Temp;
}

void Counter::showCount()
{
	cout << "Count: "<< count << endl;
}
