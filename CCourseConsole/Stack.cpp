#include "stdafx.h"
#include "Stack.h"


Stack::Stack():pHead(nullptr)
{
}


Stack::~Stack()
{
	clear();
}

bool Stack::isEmpty()
{
	if (pHead == nullptr) return true;

	return false;
}

void Stack::clear()
{
	pTemp = pHead;
	while (pTemp != nullptr)
	{
		pTemp = pTemp->pNext_;
		delete pHead;
		pHead = pTemp;
	}
}

int Stack::readHead()
{
	if (!isEmpty())
		return pHead->item;
	else
		return 0;
}

void Stack::deleteHead()
{
	pTemp = pHead->pNext_;
	delete pHead;

	pHead = pTemp;
}

Stack & Stack::add(int item)
{
	if(pHead == nullptr)
		pHead = new Node(item);
	else
	{
		pTemp = new Node(item);
		pTemp->pNext_ = pHead;
		pHead = *&pTemp;
	}


	return *this;
}
