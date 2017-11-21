#include "stdafx.h"
#include "Tree.h"
#include "MemoryCheck.h"
#include <iostream>

Tree::Tree():pRoot(nullptr)
{
}


Tree::~Tree()
{
	deleteNode(pRoot);
}

void Tree::deleteNode(Node *&pCur)
{
	if(pCur == nullptr)	return;

	deleteNode(pCur->pLeft);
	deleteNode(pCur->pRight);

	delete pCur;
}

void Tree::addRoot(Node *pPrev,Node *&cur,int item)
{
	if (cur == nullptr){
		cur = new Node(item);
		cur->pPrev = pPrev;
		return;
	}

	if (cur->item <= item){
		addRoot(cur,cur->pLeft, item); // left
	}
	else{
		addRoot(cur,cur->pRight, item); // right
	}
}

bool Tree::find(Node * pRoot, const int item)
{
	if (pRoot == nullptr)
		return false;

	bool R, L;

	if (pRoot->item == item)
		return true;

	L = find(pRoot->pLeft, item);
	R = find(pRoot->pRight, item);

	return L || R;
}

void Tree::showNodeRight(Node *root)
{
	if (root == nullptr) return;
	Node *pTemp = root;

	while (pTemp->pRight!=nullptr)
	{
		pTemp = pTemp->pRight;
	}
	
	while (pTemp != root)
	{
		pTemp = pTemp->pPrev;	
		std::cout << pTemp->pRight->item << ' ';
		showNodeLeft(pTemp->pRight);
	}

}

void Tree::showNodeLeft(Node * root)
{
	if (root == nullptr) return;
	Node *pTemp = root;

	while (pTemp->pLeft != nullptr)
	{
		std::cout << pTemp->pLeft->item << ' ';
		pTemp = pTemp->pLeft;
		showNodeRight(pTemp->pLeft);
	}
}

void Tree::showTree()
{
	showNodeRight(pRoot);
	showNodeLeft(pRoot);
	std::cout << std::endl;
}

bool Tree::findElement(const int item)
{
	return find(pRoot,item);
}

Tree& Tree::add(int item)
{
	if (pRoot == nullptr)
	{
		pRoot = new Node(item);
		return *this;
	}

	addRoot(pRoot,pRoot,item);

	return *this;
}
