#pragma once
#include "Person.h"

class CStudent :
	public CPerson
{
	int avgScore;
public:
	CStudent(const char * i_name, const char * i_sName, const char * i_fName, int i_avgScore);
	~CStudent();

	void showData();
};

