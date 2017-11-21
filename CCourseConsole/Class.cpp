#include "stdafx.h"
#include "Class.h"
#include <iostream>


Class::Class(int input):count(input)
{

}


Class::~Class()
{
}

void Class::show() const
{
	std::cout << count << std::endl;
}

void Class::show()
{
	std::cout << count*2 << std::endl;
}
