#pragma once
#include <string>
#include "MemoryCheck.h"
#include "PreDefined.h"

using namespace std;

struct namesBase
{
	const string *fNameArr = new string[NAMES_COUNT]
	{
		"Ash", "Bishop", "Cris", "David" , "Erik" , "Fedya","Gregoriy", "Nikola", "Misha", "Tom", "Andriy", "Walter", "Henk", "John", "Michel", "Edik", "Edward", "Dima", "Anton", "Mark"
	};

	const string *sNameArr = new string[NAMES_COUNT]
	{
		"Smith", "Brown", "Johnson", "Williams", "White", "Taylor", "Thomas", "Anderson", "Martin", "Tolkin", "Lee", "Shelly", "Walker", "Hiks", "Hall", "Scott", "King" , "Baker" , "Godson" , "Logvinov"
	};

};
