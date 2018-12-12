#ifndef _TREE__H
#define _TREE__H
#include <list>
#include <cmath>
using namespace std;

template<typename T>
class linkedNode;

template<typename T>
class linkedList;

class TreeNode{
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int in);
};

class Tree{
public:
	TreeNode *root;

	Tree();	
	bool searchNode(int v, TreeNode* p);
	void insertNode(int v, TreeNode* &p);
	void deleteNode(int v);
	void displayTree();
	void createMinHightTree(int *arr, int begin, int end, TreeNode* &p);
	void preOrder(TreeNode* &p);
	void createLvlLinkedList(TreeNode* p, int level, list<TreeNode> *arr);
	int getHeight(TreeNode *p, int &bal);
	bool valBST(TreeNode *p, int min, int max);
};

template<typename T>
class linkedNode{
public:
	T val;
	linkedNode* next;
	linkedNode(T in):val(in){ next = NULL;}
};

template<typename T>
class linkedList{
	linkedNode<T> *head;
public:
	int size;
	linkedList<T>(){ head = NULL; size = 0;}
	void insertNode(T p);
	linkedNode<T>* locateNode(int idx);
};

template<typename T>
void linkedList<T>::insertNode(T p){
	linkedNode<T>* tmp = head;
	if (head == NULL){
		head = new linkedNode<T>(p);
		size++;
		return;
	}
	
	while (tmp != NULL){
		if (tmp->next == NULL){
			tmp->next = new linkedNode<T>(p);
			break;
		}
		tmp = tmp->next;
	}
	size++;
}

template<typename T>
linkedNode<T>* linkedList<T>::locateNode(int idx){
	linkedNode<T>* tmp = head;
	for (int i = 0; i<idx; i++)
		tmp = tmp->next;
	return tmp;
}














#endif
