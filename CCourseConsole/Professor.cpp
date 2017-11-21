#include "stdafx.h"
#include "Professor.h"
#include <iostream>

CProfessor::CProfessor(const char * i_name, const char * i_sName, const char * i_fName, int i_publicationCount,int i_rang):
	CPerson(i_name, i_sName, i_fName),
	rang(i_rang),
	publicationCount(i_publicationCount)
{
}


CProfessor::~CProfessor()
{
}

void CProfessor::showData()
{
	CPerson::showData();
	cout << "Publication count: " << publicationCount << endl;
	cout << "Rang: " << rang << endl;
}
