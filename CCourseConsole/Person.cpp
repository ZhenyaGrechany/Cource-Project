#include "stdafx.h"
#include "Person.h"
#include <iostream>

CPerson::CPerson(const char * i_name, const char * i_sName, const char * i_fName):
	name(i_name),
	sName(i_sName),
	fName(i_fName)
{

}

CPerson::~CPerson()
{
}

void CPerson::showData()
{
	cout << "Name: " << name << endl;
	cout << "Second name: "<< sName << endl;
	cout << "Father name: "<< fName << endl;
}
