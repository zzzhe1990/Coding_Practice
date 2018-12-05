#ifndef _TREE__H
#define _TREE__H

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
};


#endif
