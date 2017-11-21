#include "stdafx.h"
#include "Singleton.h"
#include <iostream>

int Singleton::count;
int Singleton::aSize;
int *Singleton::array;

Singleton::Singleton(int size)
{
	printf("Constructor!!!\n");
	if (++count == 1 && size > 0)
	{
		array = new int[size];
		aSize = size;

		for (int i = 0; i < size; i++)
		{
			array[i] = 0;
		}
		
	}
	
	
}


Singleton::~Singleton()
{
	printf("\nDestructor!!!\n");
	if (--count == 0)
	{
		delete[] array;
	}
	

}

void Singleton::showArray()
{
	for (int i = 0; i < aSize; i++)
	{
		std::cout << array[i] << ' ';
	}
}

int Singleton::getCount()
{
	return count;
}
