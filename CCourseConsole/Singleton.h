#pragma once
class Singleton
{
	static int count;
	static int *array;
	static int aSize;
public:

	Singleton(int size = 0);
	~Singleton();

	static void showArray();

	static int getCount();
};

