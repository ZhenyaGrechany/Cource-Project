#pragma once

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Student
{
public:
	Student(string name, string secondname, int averageScore, int Age);
	Student(Student* st);

	~Student();

	string getName();
	string getSecondName();
	int getAverageScore();
	int getAge();

	int getN(char arg)
	{
		switch (arg)
		{
		case 'n':
			return tolower(name.c_str()[0]);
			break;
		case 's':
			return tolower(secondName.c_str()[0]);
			break;
		case 'a':
			return averageScore;
			break;
		case 'y':
			return age;
			break;
		default:
			return NULL;
		}

	}
private:
	const string name;
	const string secondName;
	const int averageScore;
	const int age;
};

