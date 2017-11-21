#pragma once
#include "I_Stack.h"
#include "List.h"

template <class item_t>
class Adapter :
	public I_Stack<item_t>
{
	List<item_t> *pList;
public:
	Adapter()
	{
		pList = new List<item_t>();
	}

	void pushBack(item_t item)
	{
		pList->add(item);
	}
	item_t pop()
	{
		item_t tmp = *pList->end();
		pList->delBack();
		return tmp;
	}
	bool isEmpty()
	{
		return pList->isEmpty();
	}
	void plugIn(List<item_t> *list)
	{
		delete pList;
		pList = list;
	}
	void clear()
	{
		while (!pList->isEmpty())
		{
			pList->delFirst();
		}
	}

	~Adapter()
	{
		delete pList;
	}
};

