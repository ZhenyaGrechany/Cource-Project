#pragma once
#include "Student.h"
#include "NamesBase.h"

using namespace std;

class GaSStudents
{
	Student** studentList;
	namesBase* names;
	const string *pName;

	int count;
public:
	void setSortArg(const char *argc);

	GaSStudents(int inpCount);
	~GaSStudents();

	void initStudents();

	void sortStudents();

	void printStudents();

private:
	void(GaSStudents::*sort[STUDENT_FIELDS_COUNT])(int, int) ;
	int(__cdecl *_compare)(const void *,const void *);

	char *arg;
	int arglistS;
	bool isSetArg;

	int checkCount(const int count);

	void swap(int f, int s);

	void pSortAge(int fRange,int sRange);
	void pSortName(int fRange, int sRange);
	void pSortSname(int fRange, int sRange);
	void pSortAvgScore(int fRange, int sRange);

	int compare(const void *pV1, const void *pV2)
	{
		return *(int*)pV2 - *(int*)pV1;
	}

	template<typename T>
	bool ftos(T a, T b); 

	template<typename T>
	bool stof(T a, T b);

};

template<typename T>
inline bool GaSStudents::ftos(T a, T b)
{
	return a>b;
}

template<typename T>
inline bool GaSStudents::stof(T a, T b)
{
	return a<b;
}
