#pragma once

#include "PreDefined.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int getInt()
{
	char *arrayChar = new char[CHAR_MAX_TOINT];
	int count = 0;
	char tempChar;
	short int tempGetch;
	int result;


	while (true)
	{
		if (count >= CHAR_MAX_TOINT)
		{
			cout << "\nINT_MAX lenght is 10" << endl;
			break;
		}

		tempGetch = _getch();
		if (tempGetch == 13)
			break;
		else
			tempChar = (char)tempGetch;

		if (tempChar >= (int)'0' && tempChar <= (int)'9')
		{

		}
		else
			continue;

		arrayChar[count++] = tempChar;
		cout << (char)tempGetch;

	}

	result = atoi(arrayChar);

	if (result > INT_MAX)
	{
		cout << endl;
		return INT_MAX;
	}

	cout << endl;

	delete[] arrayChar;
	return result;
}