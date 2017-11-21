#pragma once
#include <iostream>
#include "MemoryCheck.h"
using namespace std;

template<class item_t>
class List
{
private:
	int lenght_;

	struct Node
	{
		item_t item;

		Node *pNext_;
	};

	mutable Node *pCur_;
	mutable Node *pTemp_;
	Node *pEnd_;
	Node *pBegin_;
public:
	List();
	~List();

	class Iterator {
		Node * m_pIter;
	public:       
		Iterator()
		{}
		Iterator(Node *pStart)
		{
			m_pIter = pStart;
		}
		~Iterator(){}

		void operator ++(int)
		{
			if (m_pIter != nullptr)
				m_pIter = m_pIter->pNext_;
		}
			
		Iterator& operator = (const Iterator & Right)
		{
			m_pIter = Right.m_pIter;
			return *this;
		}
		Iterator& operator = (const int & Right)
		{
			int i = 0;
			while (m_pIter != nullptr && i < Right)
			{
				m_pIter = m_pIter->pNext_;
				i++;
			}
			return *this;
		}
		Node * operator->()
		{
			return List<item_t>::Iterator::m_pIter;
		}

		bool operator != (const Iterator& Right)
		{
			return Right.m_pIter->item != m_pIter->item;
		}
		item_t& operator*()
		{
			item_t NULL_t = 0;
			if (this->m_pIter == nullptr)
				return NULL_t;
			return m_pIter->item;
		}
	};

	Iterator begin() { return  Iterator(pBegin_); }
	Iterator end() { return  Iterator(pEnd_); }
	

	friend ostream& operator<<(ostream& out, List<item_t> &list)
	{
		list.pCur_ = list.pBegin_;

		while (list.pCur_ != nullptr)
		{
			out << list.pCur_->item << ' ';
			list.pCur_ = list.pCur_->pNext_;
		}
		return out;
	}
	void sort(bool(*compFunc)(item_t, item_t));

	bool isEmpty();


	List<item_t>& add(item_t data);
	List<item_t>& addByInd(int index, item_t item);
	List<item_t>& delByInd(int index);
	List<item_t>& delByItem(item_t item);
	List<item_t>& delBack();
	List<item_t>& delFirst();
private:
	size_t getSize();
};

template<class item_t>
List<item_t>::List() :
	pEnd_(nullptr),
	pCur_(nullptr),
	pTemp_(nullptr),
	pBegin_(nullptr)
{
}



template<class item_t>
List<item_t>::~List()
{
	if (pBegin_ == nullptr) return;

	pCur_ = pBegin_;
	pTemp_ = pCur_->pNext_;

	while (pCur_ != nullptr)
	{
		pTemp_ = pCur_->pNext_;
		delete pCur_;
		pCur_ = pTemp_;
	}

}

template<class item_t>
List<item_t> & List<item_t>::add(item_t data)
{
	pTemp_ = new Node;
	pTemp_->item = data;
	pTemp_->pNext_ = nullptr;

	if (pBegin_ == nullptr) {
		pEnd_ = pTemp_;
		pBegin_ = pEnd_;
	}
	else {
		pEnd_->pNext_ = pTemp_;
		pEnd_ = pTemp_;
	}

	return *this;
}

template<class item_t>
List<item_t> & List<item_t>::addByInd(int index, item_t item)
{
	size_t size = getSize();

	if (index > size)
		add(item);
	else
	{
		if (index == 0)
		{
			pTemp_ = new Node;
			pTemp_->item = item;
			pTemp_->pNext_ = pBegin_;

			pBegin_ = pTemp_;
			return *this;
		}
		pCur_ = pBegin_;
		for (int i = 0; i < index - 1; i++)
		{
			pCur_ = pCur_->pNext_;
		}

		pTemp_ = new Node;
		pTemp_->item = item;
		pTemp_->pNext_ = pCur_->pNext_;

		pCur_->pNext_ = pTemp_;

	}


	return *this;
}

template<class item_t>
void List<item_t>::sort(bool(*compFunc)(item_t, item_t))
{
	if (pBegin_ == nullptr) return;

	size_t size = getSize();
	item_t *tmpArr = new item_t[size];

	pTemp_ = pBegin_;
	for (size_t i = 0; i < size; i++)
	{
		tmpArr[i] = pTemp_->item;
		pTemp_ = pTemp_->pNext_;
	}

	for (int i = 0; i<size; i++)
	{
		for (int j = i; j>0; j--)
		{
			if (compFunc(tmpArr[j - 1], tmpArr[j]))
			{
				item_t tmp = tmpArr[j - 1];
				tmpArr[j - 1] = tmpArr[j];
				tmpArr[j] = tmp;
			}
		}
	}

	pTemp_ = pBegin_;
	for (size_t i = 0; i < size; i++)
	{
		pTemp_->item = tmpArr[i];
		pTemp_ = pTemp_->pNext_;
	}

	delete[] tmpArr;
}

template<class item_t>
bool List<item_t>::isEmpty()
{
	if (pBegin_ == nullptr) return true;

	return false;
}

template<class item_t>
List<item_t> & List<item_t>::delByInd(int index)
{
	pCur_ = pBegin_;

	if (index == 0)
	{
		pBegin_ = pCur_->pNext_;
		delete pCur_;
		return *this;
	}

	for (int i = 0; i < index - 1; i++)
	{
		pCur_ = pCur_->pNext_;
	}

	pTemp_ = pCur_->pNext_->pNext_;
	delete pCur_->pNext_;

	pCur_->pNext_ = pTemp_;

	return *this;
}

template<class item_t>
List<item_t> & List<item_t>::delByItem(item_t item)
{
	pCur_ = pBegin_;

	if (pBegin_->item == item)
	{
		pBegin_ = pCur_->pNext_;
		delete pCur_;
		return *this;
	}

	while (pCur_->pNext_->item != item) {
		pCur_ = pCur_->pNext_;
	}

	pTemp_ = pCur_->pNext_->pNext_;
	delete pCur_->pNext_;

	pCur_->pNext_ = pTemp_;

	return *this;
}

template<class item_t>
List<item_t> & List<item_t>::delBack()
{
	if (isEmpty()) return *this;
	pTemp_ = pBegin_;

	while (pTemp_->pNext_ != pEnd_)
	{
		pTemp_ = pTemp_->pNext_;
	}
	delete pEnd_;

	pTemp_->pNext_ = nullptr;

	pEnd_ = pTemp_;
	return *this;
}

template<class item_t>
List<item_t> & List<item_t>::delFirst()
{
	if (isEmpty()) return *this;
	pTemp_ = pBegin_->pNext_;

	delete pBegin_;

	pBegin_ = pTemp_;

	return *this;
}

template<class item_t>
size_t List<item_t>::getSize()
{
	if (pBegin_ == nullptr) return 0;
	size_t size = 1;

	pTemp_ = pBegin_;
	while (pTemp_ != pEnd_)
	{
		pTemp_ = pTemp_->pNext_;
		size++;
	}

	return size;
}