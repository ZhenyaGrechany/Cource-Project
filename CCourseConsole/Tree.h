#pragma once
class Tree
{
	struct Node
	{
		int item;
		Node *pRight;
		Node *pLeft;
		Node *pPrev;
		Node(int data) :item(data), pLeft(nullptr), pRight(nullptr),pPrev(nullptr) {}
	};

	Node *pRoot;
public:
	Tree();
	~Tree();

	void showTree();
	bool findElement(const int item);
	Tree& add(int item);
private:
	void deleteNode(Node *&pRoot);
	void addRoot(Node *pPrev,Node *&cRoot,int item);
	bool find(Node *pRoot, const int item);

	void showNodeRight(Node *root);
	void showNodeLeft(Node *root);
};

