#pragma once
#include <string>
using namespace std;

class CPerson
{
public:
	CPerson(const char *i_name,const char *i_sName,const char *i_fName);
	virtual ~CPerson();

	void showData();
protected:
	const string name;
	const string sName;
	const string fName;
};

