#pragma once
#include <time.h>
#include <random>

using namespace std;

void initArray(double *array, int size)
{
	srand(time(0));

	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 100 * 0.1 + 'A';
	}
}

template<typename T>
void initArray(T *array, int size)
{
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 30 + 'A';
	}
}

template<typename T>
void showArray(T* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
}

template<typename T>
void sortArray(T* array, int size, bool(__cdecl *pAB)(T, T))
{
	T pInd;
	for (int i = 1; i<size; i++)
	{
		for (int j = i; pAB(array[j - 1], array[j]) && j>0; j--)
		{
			pInd = array[j - 1];
			array[j - 1] = array[j];
			array[j] = pInd;
		}
	}
}

template<typename T>
void arrayQsort(T* array, int size, bool(__cdecl *pAB)(T, T))
{
	T pInd;
	for (int i = 0; i<size; i++)
	{
		for (int j = i; pAB(array[j - 1], array[j]) && j>0; j--)
		{
			
		}
	}
}

