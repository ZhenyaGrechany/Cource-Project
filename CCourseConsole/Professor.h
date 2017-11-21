#pragma once
#include "Person.h"
class CProfessor :
	public CPerson
{
	int rang;
	int publicationCount;
public:
	CProfessor(const char * i_name, const char * i_sName, const char * i_fName, int i_publicationCount,int i_rang);
	~CProfessor();

	void showData();
};

