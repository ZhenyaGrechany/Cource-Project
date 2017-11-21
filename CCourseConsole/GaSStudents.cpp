#include "stdafx.h"
#include "GaSStudents.h"
#include <random>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <crtdbg.h>
#include "MemoryCheck.h"
#include "PreDefined.h"


GaSStudents::GaSStudents(int inpCount):
		studentList(NULL)
{
	pName = new string("Student generator");
	count = checkCount(inpCount);
	names = new namesBase;
	studentList = new Student*[count] {NULL};
}


GaSStudents::~GaSStudents()
{
	for (int i = 0;studentList[i]!=NULL && i < count; i++)
		delete studentList[i];
	delete[] studentList;
	delete[] names->fNameArr;
	delete[] names->sNameArr;
	delete names;
	delete pName;
}



void GaSStudents::initStudents()
{
	srand((unsigned int)time(NULL));
	int fName;
	int sName;
	int avgScore;
	int age;

	for (int i = 0; i < count; i++)
	{
		fName = rand() % NAMES_COUNT;
		sName = rand() % NAMES_COUNT;
		avgScore = rand() % 100 + 101;
		age = rand()%6+16;
		studentList[i] = new Student(names->fNameArr[fName], names->sNameArr[sName], avgScore, age);
	}
}


void GaSStudents::sortStudents()
{
	if (isSetArg)
	{
		int first(0), last(0);
		int num(1), curInd(0);

		(this->*sort[0])(0, count);
		for (int i = 1; i < arglistS; i++)
		{
			if (arg[i] == 'L')
				break;

			first = 0;
			last = 0;
			for (size_t k = 0; k < count; k++)
			{
				first = last;
				last = first + 1;
				for (int l = first; l < count + 1; l++)
				{
					if (studentList[l]->getN(arg[i - 1]) == studentList[l + 1]->getN(arg[i - 1]))
						last++;
					else
						break;
					if (last >= count - 1)
						break;
				}

				if (last >= count - 1)
					break;
				num++;
				(this->*sort[i])(first, last);
			}


		}

		delete arg;
	}
	else
		puts("Please set sort arguments");
}

void GaSStudents::setSortArg(const char *argc)
{
	int argMS(0), tmpc(0), priorArSize(STUDENT_FIELDS_COUNT);
	char nullChar('L');
	char* prior = new char[priorArSize];
	for (int i = 0; i < priorArSize; i++)
		prior[i] = nullChar;
	while (argc[argMS++] != '\0');
	argMS--;
	for (int i = 0; i < argMS; i++)
	{
		if (argc[i] == '%' && argc[i + 1] != ' ' && argc[i + 1] != '%')
			prior[tmpc++] = tolower(argc[i + 1]);
		if (tmpc + 1 > priorArSize)
			break;
	}
	
	int curInd(0);
	for (int i = 0; i < priorArSize; i++)
	{
		switch (prior[i])
		{
		case 'n':
			GaSStudents::sort[curInd++] = &GaSStudents::pSortName;
			break;
		case 's':
			GaSStudents::sort[curInd++] = &GaSStudents::pSortSname;
			break;
		case 'a':
			GaSStudents::sort[curInd++] = &GaSStudents::pSortAvgScore;
			break;
		case 'y':
			GaSStudents::sort[curInd++] = &GaSStudents::pSortAge;
			break;
		case 'L':
			break;
		default:
			break;
		}
	}

	arg = prior;
	arglistS = priorArSize;
	isSetArg = true;
}


void GaSStudents::printStudents()
{
		for (int i = 0;studentList[i]!=NULL && i < count; i++)
		{

			cout << i + 1
				<< ": "
				<< studentList[i]->getName()
				<< " "
				<< studentList[i]->getSecondName()
				<< "          -> "
				<< "Average score: "
				<< studentList[i]->getAverageScore()
				<< "  Age: "
				<< studentList[i]->getAge()
				<< endl;
		}
}

int GaSStudents::checkCount(const int count)
{
	WRITE_INPUT_COUNT(count);

	if (count > MAX_STUDENT_LIST_SIZE)
	{
		cout << "Max student list size: " << MAX_STUDENT_LIST_SIZE << endl;
		WRITE_CHANGED_COUNT(MAX_STUDENT_LIST_SIZE);
		return MAX_STUDENT_LIST_SIZE;
	}
	else if (count < MIN_STUDENT_LIST_SIZE)
	{
		cout << "Min student list size: " << MIN_STUDENT_LIST_SIZE << endl;
		WRITE_CHANGED_COUNT(MIN_STUDENT_LIST_SIZE);
		return MIN_STUDENT_LIST_SIZE;
	}

	return count;
}

void GaSStudents::swap(int f, int s)
{
	Student* tmp;
	tmp = *&studentList[f];
	studentList[f] = *&studentList[s];
	studentList[s] = tmp;
}

void GaSStudents::pSortAge(int fRange, int sRange)
{
	for (int i = fRange+1; i<sRange; i++)
	{
		for (int j = i;j>fRange; j--)
		{
			if(ftos(studentList[j-1]->getAge(), studentList[j]->getAge()) ==true)
				swap(j-1,j);
		}
	}
}

void GaSStudents::pSortName(int fRange, int sRange)
{
	for (int i = fRange+1; i<sRange; i++)
	{
		for (int j = i; j>fRange;j--)
		{
			if(ftos(tolower(studentList[j - 1]->getName().c_str()[0]), tolower(studentList[j]->getName().c_str()[0]))==true)
				swap(j - 1, j);
		}
	}
}

void GaSStudents::pSortSname(int fRange, int sRange)
{
	for (int i = fRange + 1; i<sRange; i++)
	{
		for (int j = i;j>fRange; j--)
		{
			if (ftos(tolower(studentList[j - 1]->getSecondName().c_str()[0]), tolower(studentList[j]->getSecondName().c_str()[0])) == true)
				swap(j - 1, j);
		}
	}
}

void GaSStudents::pSortAvgScore(int fRange, int sRange)
{
	for (int i = fRange + 1; i<sRange; i++)
	{
		for (int j = i; j>fRange; j--)
		{
			if(ftos(studentList[j - 1]->getAverageScore(), studentList[j]->getAverageScore())==true)
			swap(j - 1, j);
		}
	}
}

