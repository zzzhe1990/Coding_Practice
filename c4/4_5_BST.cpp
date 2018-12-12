#include <iostream>
#include <iterator>
#include "tree.h"
#include <climits>

using namespace std;

template<typename T>
void createLvlLinkedList(TreeNode* p, int lvl, linkedList<T> *arr){
	if (p != NULL){
		arr[lvl].insertNode(*p);
		lvl++;			
		createLvlLinkedList(p->left, lvl, arr);
		createLvlLinkedList(p->right, lvl, arr);
	}	
}

template<typename T>
void displayTreeInLinkedList(linkedList<T> *arr){
	int i = 0;
	while(arr[i].size != 0){
		cout << i << ": ";

		for (int j=0; j<arr[i].size; j++){
			cout << (*(arr[i].locateNode(j))).val.val << " ";
		}
		cout << endl;
		i++;
	}
}

void displayTreeInLvl(list<TreeNode> *arr){
	int i = 0;
	list<TreeNode>::iterator itr;
	while(arr[i].begin() != arr[i].end()){
		cout << i << ": ";
		for (itr = arr[i].begin(); itr != arr[i].end(); itr++){
			cout << itr->val << " ";
		}
		cout << endl;
		i++;
	}
}

int main(){
	int* arr = new int[15];
	Tree bst;

	for (int i=0; i<15; i++){
		arr[i] = i;
//		bst.insertNode(treeArray[i], bst.root);
	}

	bst.createMinHightTree(arr, 0, 14, bst.root);
	bst.displayTree();

	list<TreeNode> *listarr = new list<TreeNode>[100];
	


	linkedList<TreeNode> *linkedListarr;
	linkedListarr = new linkedList<TreeNode>[20];

	createLvlLinkedList(bst.root, 0, linkedListarr);

	displayTreeInLinkedList(linkedListarr);

	Tree bst1;
	bst1.root = new TreeNode(10);
	bst1.root->left = new TreeNode(5);
	bst1.root->right = new TreeNode(20);
	bst1.root->left->left = new TreeNode(1);
	bst1.root->left->right = new TreeNode(15);
	
	bst1.createLvlLinkedList(bst1.root, 0, listarr);
	displayTreeInLvl(listarr);

	bool valBST = bst1.valBST(bst1.root, INT_MIN, INT_MAX);
	if (valBST)
		cout << "This is a binary search tree." << endl;
	else
		cout << "This is not a binary search tree." << endl;

	delete[] arr;
	delete[] listarr;
	delete[] linkedListarr;
	
	return 0;
}
