#include "stdafx.h"
#include "CStudent.h"
#include <iostream>

CStudent::CStudent(const char * i_name, const char * i_sName, const char * i_fName,int i_avgScore):
	CPerson(i_name,i_sName,i_fName),
	avgScore(i_avgScore)
{
}


CStudent::~CStudent()
{
}

void CStudent::showData()
{
	CPerson::showData();
	cout <<"Average score: "<<  avgScore << endl;
}
