#include "stdafx.h"
#include "Student.h"



Student::Student(string name, string secondName, int averageScore, int Age) :
	name(name),
	secondName(secondName),
	averageScore(averageScore),
	age(Age)
{
	
}

Student::Student(Student* st) :
	name(st->getName()),
	secondName(st->getSecondName()),
	averageScore(st->getAverageScore()),
	age(st->getAge())
{
	
}

Student::~Student()
{

}

string Student::getName()
{
	return this->name;
}

string Student::getSecondName()
{
	return this->secondName;
}

int Student::getAverageScore()
{
	return this->averageScore;
}

int Student::getAge()
{
	return this->age;
}