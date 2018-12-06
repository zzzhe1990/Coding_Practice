#include <iostream>
#include <queue>
#include "tree.h"
using namespace std;

TreeNode::TreeNode(int in){
	val = in;
	left = NULL;
	right = NULL;
}

Tree::Tree(){
	root = NULL;
}

bool Tree::searchNode(int v, TreeNode *p){
	if (p == NULL){
		return false;
	}
	if ( v == p->val){
		return true;
		
	}
	bool exist;
	if (v < p->val){
		exist = searchNode(v, p->left);
	}
	else if (v > p->val){
		exist =	searchNode(v, p->right);
	}
	return exist;
}

void Tree::insertNode(int v, TreeNode* &p){
	if (p == NULL){
		p = new TreeNode(v);
	}
	else if (v == p->val){
	}
	else if (v < p->val){
		insertNode(v, p->left);
	}	
	else if (v > p->val){
		insertNode(v, p->right);
	}
	else
		;
}

void Tree::displayTree(){
	if (root == NULL)
		return;
	queue<TreeNode*> que;	
	que.push(root);
	TreeNode* tmp;

	while (!que.empty()){
		tmp = que.front();
		que.pop();
		cout << tmp->val << " ";
		if (tmp->left != NULL)
			que.push(tmp->left);
		if (tmp->right != NULL)
			que.push(tmp->right);
	}
	cout << endl;
}

void Tree::createMinHightTree(int* arr, int begin, int end, TreeNode* &p){
	if (begin > end)
		return;
	int mid = (end + begin) / 2;
	p = new TreeNode(arr[mid]); 
	
	createMinHightTree(arr, begin, mid-1, p->left);
	createMinHightTree(arr, mid+1, end, p->right);
}

void Tree::preOrder(TreeNode* &p){
	if (p != NULL){
		;
		preOrder(p->left);
		preOrder(p->right);
	}
}

void Tree::createLvlLinkedList(TreeNode* p, int lvl, list<TreeNode> *arr){
	if (p != NULL){
		arr[lvl].push_back(p->val);
		lvl++;
		createLvlLinkedList(p->left, lvl, arr);
		createLvlLinkedList(p->right, lvl, arr);
	}
}




















