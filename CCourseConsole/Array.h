#pragma once
#include "MemoryCheck.h"
#include <iostream>
#include <conio.h>
#include "PreDefined.h"
#include <string>



using namespace std;

enum errors
{
	succes,
	fileError,
	memoryError,
	readError
};

class ArrMult;
class BackUp;
class Array
{
	int *currentArray;

	int arraySize, 
		currentIndex;

	bool _echo = ARRAY_ECHO;

	BackUp *writer;
public:
	Array(void);
	Array(int inputSize);
	Array(int *inputArray, int inputArraySize);
	Array(const Array &R);

	~Array();

	void operator++(int);
	Array operator+(const Array &R);
	friend Array operator+(Array &First , int Second);
	friend Array operator+(int First,const Array &Second);


	Array& operator=(const Array &R);


	void initFromFile(const char *fileName);
	void writeToFile(const char *arFileName);
	void showArray();

	int get();
	int getSize();

	void sortArray();
	void setArray(int *inputArray,int inputArraySize);
	void setArray();
	void push_Back(int a);
	friend ostream& operator<<(ostream &out, const Array &R);

	void echoON();
	void echoOFF();
private:

	void initArray();

	void clear();

	void addMemory();

};

template<class T,class C>
void replace(T *a, C &b)
{
	char buff[sizeof(T)];
	T Temp(b);
	memcpy(buff, a, sizeof(T));
	memcpy(a, &Temp, sizeof(T));
	memcpy(&Temp, buff, sizeof(T));
}
