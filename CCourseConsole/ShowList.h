#pragma once
#include "STL.h"
using namespace std;

template<class item>
void showList(item &lst)
{
	for (auto &obj : lst)
	{
		cout << obj << ' ';
	}
}

template<class item>
void showMap(item &map)
{
	for (auto &obj : map)
	{
		cout << obj.first << ' ' << obj.second <<endl;
	}
}

template<class item>
void showMapwPair(item &map)
{
	for (auto &obj : map)
	{
		cout << obj.second << ' ' << obj.first.second << ' ' <<  endl;
	}
}

template<class item>
void showMapByCrit(item &map)
{
	auto iter = find_if(map.begin(), map.end(), &criteria);
	while (iter != map.end())
	{
		cout << iter->first << ' ' << iter->second << endl;
		iter = find_if(++iter, map.end(), &criteria);
	}
	
}

bool criteria(pair<string,float> obj)
{
	return obj.second > 100;
}