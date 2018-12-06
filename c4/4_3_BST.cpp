#include <iostream>
#include <iterator>
#include "tree.h"

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
	
	bst.createLvlLinkedList(bst.root, 0, listarr);

	displayTreeInLvl(listarr);

	linkedList<TreeNode> *linkedListarr;
	linkedListarr = new linkedList<TreeNode>[20];

	createLvlLinkedList(bst.root, 0, linkedListarr);

	displayTreeInLinkedList(linkedListarr);


	delete[] arr;
	delete[] listarr;
	delete[] linkedListarr;
	
	return 0;
}
