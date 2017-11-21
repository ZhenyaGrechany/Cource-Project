#pragma once
#include "STL.h"
#include "ShowList.h"
#include <iostream>
#include <string>
using namespace std;

void shop()
{
	srand(time(0));
	map<string, float> products;
	products.insert(pair<string, float>("pepsi", 20.5));
	products.insert(pair<string, float>("nuke-cola", 25.5));
	products.insert(pair<string, float>("super bread", 2351.5));
	products["vodka"] = 35.1;
	products["JIVCHIK"] = 2;
	products["beer"] = 15.7;
	products["chokolate"] = 23.4;
	products["milk"] = 20;

	showMapByCrit(products);

	string input;
	showMap(products);

	float money = 0;
	map<pair<int,float>, string> bucket;
	int counter = 0;

	while (money < 150)
	{
		cout << "\n"<<"Bucket cost " << money << " Gryvna" << endl;
		cin >> input;
		system("cls");
		showMap(products);
	
		map<string,float>::iterator itr = products.find(input);

		if (itr != products.end())
		{
			cout << "\n"<<"In bucket: " << endl;
			money = money + itr->second;
			bucket.insert(pair<pair<int,float>, string>(pair<int, float>(rand(), itr->second),itr->first));
			showMapwPair(bucket);
		}
		
		
		
	}
	
}