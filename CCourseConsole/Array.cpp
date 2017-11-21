#include "stdafx.h"
#include "Array.h"
#include "ArrMult.h"
#include "BackUp.h"

Array::Array(void) :
	arraySize(0),
	currentIndex(0),
	currentArray(0)
{

}


Array::Array(int inputSize) :
	arraySize(inputSize),
	currentIndex(0),
	currentArray(NULL)
{
	if(_echo == true)cout << "Started constructing... " << this;
	if (inputSize <= 0)
	{
		arraySize = 1;
	}

	currentArray = new int[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		currentArray[i] = 0;
	}

	if (_echo == true)cout << "	Array constructed successfully: " << this << endl;
}

Array::Array(int *inputArray, int inputArraySize):
	arraySize(inputArraySize),
	currentArray(inputArray),
	currentIndex(inputArraySize)
{
	if (_echo == true)cout << "Started constructing... " << this;


	if (arraySize < 0)
	{
		arraySize = 0;
	}
	

	if (_echo == true)cout << "	Array constructed successfully: " << this << endl;
}

Array::Array(const Array &R):
	arraySize(R.arraySize),
	currentIndex(R.currentIndex),
	currentArray(0)
{
	if (_echo == true)cout << "Started constructing... " << this;

	if (arraySize != 0)
	{
		currentArray = new int[arraySize];
		memcpy(currentArray, R.currentArray, sizeof(int)*currentIndex);
	}

	if (_echo == true)cout << "	Copy construct success: " << this << " From: " << &R << endl;
}


Array::~Array()
{
	if (_echo == true)cout << "Started destructing... " << this;

	if (currentArray != 0)
		delete[] currentArray;

	if (_echo == true)cout << "		Array destruct: " << this <<  endl;
}


void Array::clear()
{

	int *pTemp = new int[currentIndex];

	memcpy(pTemp, currentArray, sizeof(int) *currentIndex);

	delete[] currentArray;

	this->currentArray = pTemp;
	this->arraySize = currentIndex;

}

void Array::addMemory()
{
	int arrayOldSize;

	if (arraySize< 0)
		arraySize *= -1;

	if (arraySize == 0)
		arraySize = 1;
	

		int arrayNewSize = arraySize + arraySize / 2;
		arrayOldSize = arraySize;
		int *pTemp = new int[arrayNewSize];

		memcpy(pTemp, currentArray, sizeof(int) *arraySize);

		delete[] currentArray;
		this->currentArray = pTemp;
		cout << "old size: " << arraySize << " / new size: " << arrayNewSize << " " << this << endl;
		this->arraySize = arrayNewSize;

		for  (int i = arrayOldSize; i < arrayNewSize;i++)
		{
			currentArray[i] = 0;
		}


}

void Array::initArray()
{
	string input;
	int cInt;
	int cGetch = 0;
	currentIndex = 0;

	while (true)
	{
		cout << currentIndex << ": ";
		
		cin >> input;

		if (atoi(input.c_str()) == 0)
			break;
		cInt = atoi(input.c_str());


		push_Back(cInt);

		if (currentIndex > MAX_ARRAY_SIZE)
			break;

	}
}

void Array::showArray()
{
	for  (int i = 0; i < currentIndex;i++)
	{
		cout << currentArray[i] << " ";
	}
	cout << endl;
}

int Array::getSize()
{
	return arraySize;
}

void Array::setArray()
{
	initArray();
	clear();
}

void Array::push_Back(int a)
{
	if (arraySize == currentIndex)
		addMemory();
	currentArray[currentIndex++] = a;
}

void Array::echoON()
{
	_echo = true;
}

void Array::echoOFF()
{
	_echo = false;
}

void Array::sortArray()
{

}

void Array::setArray(int *inputArray, int inputArraySize)
{
	if (currentArray != 0)
		delete[] currentArray;

	currentArray = inputArray;
	arraySize = inputArraySize;
	currentIndex = inputArraySize;
}

int Array::get()
{
	return *currentArray;
}

void Array::initFromFile(const char *fileName)
{
	int _errno(0);
	writer = new BackUp();
	int tmpSize;

	delete currentArray;
	currentArray = (int *)writer->Read(fileName, &tmpSize, &_errno);

	arraySize = tmpSize / sizeof(int);
	currentIndex = tmpSize / sizeof(int);

	if (_errno == succes)
		cout << "array initialization from file was success" << endl;

	delete writer;
}

void Array::writeToFile(const char *arFileName)
{
	writer = new BackUp();

	writer->Write(arFileName,currentArray,currentIndex);
	
	delete writer;
}

void Array::operator++(int)
{
	for (int i = 0; i < arraySize; i++)
	{
		currentArray[i]++;
	}
}

Array Array::operator+(const Array & R)
{
	int *tmpobj = new int[currentIndex+R.currentIndex];
	int *last= tmpobj + currentIndex;
	memcpy_s(tmpobj, sizeof(int)*currentIndex, currentArray, sizeof(int)*currentIndex);
	memcpy(last, R.currentArray, sizeof(int)*R.currentIndex);


	for (size_t i = 0; i < currentIndex; i++)
	{
		cout << tmpobj[i] << ' ';
	}
	cout << '(' <<this<< '-' << *&currentArray << '-' << ')' << ' ';
	cout << '+' << ' ';
	for (size_t i = 0; i < R.currentIndex; i++)
	{
		cout << R.currentArray[i] << ' ';
	}
	cout << '(' << &R << '-' << *&R.currentArray << '-'<<')' << ' ';
	cout << '=' << ' ';


	for (size_t i = 0; i < currentIndex + R.currentIndex; i++)
	{
		cout << tmpobj[i] << ' ';
	}
	 
	cout << '(' << *tmpobj << '(' << *&tmpobj << ')' << ')' << endl;

	return Array(tmpobj, currentIndex + R.currentIndex);
}

Array operator+(Array & First, int second)
{
	Array Temp(First.arraySize);

	Temp.currentIndex = First.currentIndex;
	for (size_t i = 0; i < Temp.currentIndex; i++)
	{
		Temp.currentArray[i] = First.currentArray[i] + second;
	}

	return Temp;
}

Array operator+(int First, const Array & Second)
{
	Array Temp(Second.arraySize);

	Temp.currentIndex = Second.currentIndex;
	for (size_t i = 0; i < Temp.currentIndex; i++)
	{
		Temp.currentArray[i] = Second.currentArray[i] + First;
	}

	return Temp;
}

//Array& Array::operator=(const Array & R)
//{
//	if (this != &R)
//	{
//		if (currentArray != 0)
//			delete[] currentArray;
//
//		arraySize = R.arraySize;
//		currentIndex = R.currentIndex;
//		
//		currentArray = new int[arraySize];
//
//		memcpy(currentArray, R.currentArray, sizeof(int)*currentIndex);
//	}
//	return *this;
//}

Array& Array::operator=(const Array & R)
{
	if (this != &R)
	{
		replace(this,R);
	}
	return *this;
}

ostream& operator<<(ostream &out, const Array &R)
{
	for (int i = 0; i < R.currentIndex; i++)
	{
		out << R.currentArray[i] << ' ';
	}
	return out;
}