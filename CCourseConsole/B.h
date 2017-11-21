#pragma once
#include <iostream>



using namespace std;

class A;
class B
{
	friend A;
	int mB;
public:

	B();
	~B();

	void Func(A *pA);

	void showAA(A* pA);

};
