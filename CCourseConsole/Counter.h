#pragma once
#include <iostream>

using namespace std;

class Counter
{
	int count;
public:
	Counter(int inputCount);
	Counter(const Counter &C);
	~Counter();

	Counter operator+(const Counter &R);

	void showCount();
};

