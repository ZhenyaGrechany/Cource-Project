#pragma once
#include "STL.h"
#include <string>
using namespace std;

struct people {
	string name;
	string adress;
	int phone;
};

void peopleData()
{
	people p = { "Alex", "Foo drive 32", 312 };
	people p1 = { "Kolya" , "Po 314" , 12345 };
	vector<people*> peoples = { &p,
	 &p1};

	char* req;
	cin >> req;
	auto itr = find(peoples.begin(), peoples.end(), req);
	//if (itr != peoples.end())
		//cout << *itr << ' ' << *itr << endl;

}