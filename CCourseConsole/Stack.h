#pragma once


class Stack
{
	struct Node
	{
		int item;

		Node *pNext_;
		Node(int inItem):item(inItem),pNext_(nullptr){}
	};

	Node* pTemp;
	Node* pHead;
public:
	Stack();
	~Stack();

	bool isEmpty();
	void clear();
	int readHead();
	void deleteHead();
	Stack& add(int item);
};

