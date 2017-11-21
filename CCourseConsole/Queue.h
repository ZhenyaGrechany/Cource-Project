#pragma once
#include <iostream>
using namespace std;


template <class item_t>
class Queue
{
	template <class item_n>
	struct Node {
		item_n item;

		Node *pNext;
		Node(item_n nItem):item(nItem),pNext(nullptr){}
	};

	Node<item_t> *pHead;
	mutable Node<item_t> *pTemp;
	Node<item_t> *pCur;

	const int size_max;
	int size_cur;
public:
	Queue(const int size_max);
	~Queue();

	bool isFull();
	bool isEmpty();

	int getCount();
	int getHead();

	void popItem();
	void showState();

	Queue& addItem(item_t item);
	
	friend ostream& operator<<(ostream& out,const Queue<item_t> &qlst)
	{
		qlst.pTemp = qlst.pHead;
		out << qlst.size_cur << ": ";
		for (int i = 0; i < qlst.size_cur; i++)
		{
			out  << qlst.pTemp->item << "  ";
			qlst.pTemp = qlst.pTemp->pNext;
		}

		return out;
	}

private:
	
};

template <class item_t>
Queue<item_t>::Queue(const int size_m) :size_max(size_m), pHead(nullptr), size_cur(0)
{
}

template <class item_t>
Queue<item_t>::~Queue()
{
	while (pHead != nullptr)
	{
		popItem();
	}
}

template<class item_t>
inline bool Queue<item_t>::isFull()
{
	if (size_cur == size_max) return true;
	return false;
}

template<class item_t>
inline bool Queue<item_t>::isEmpty()
{
	if (pHead == nullptr) return true;
	return false;
}

template<class item_t>
int Queue<item_t>::getCount()
{
	return size_cur;
}

template<class item_t>
int Queue<item_t>::getHead()
{
	if (!isEmpty())
		return pHead->item;
	return 0;
}

template<class item_t>
void Queue<item_t>::popItem()
{
	if (pHead == nullptr)
		return;
	pTemp = pHead->pNext;
	delete pHead;
	pHead = pTemp;
	size_cur--;
}

template<class item_t>
inline void Queue<item_t>::showState()
{
	cout << "Full? - " << isFull() << endl;
	cout << "Empty? - " << isEmpty() << endl;
}

template <class item_t>
Queue<item_t>& Queue<item_t>::addItem(item_t item)
{
	if (!isFull())
		if (isEmpty())
		{
			pHead = new Node<item_t>(item);
			pCur = pHead;
			size_cur++;
			return *this;
		}
		else
		{
			pCur->pNext = new Node<item_t>(item);
			pCur = pCur->pNext;
			size_cur++;
		}

	return *this;
}
