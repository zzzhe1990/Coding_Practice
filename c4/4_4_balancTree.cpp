#include <iostream>
#include <iterator>
#include "tree.h"

using namespace std;

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

bool balanced(Tree bst, int &treeHeight){
	int bal;
	treeHeight = bst.getHeight(bst.root, bal);
	if (bal == -99)
		return false;
	else
		return true;
}

int main(){
	int* arr = new int[20];
	Tree bst;

	for (int i=0; i<15; i++){
		arr[i] = i * 10;
//		bst.insertNode(treeArray[i], bst.root);
	}
	arr[15] = 11;
	arr[16] = 15;
	arr[17] = 13;
	arr[18] = 12;
	arr[19] = 21;

	for (int i=0; i<19; i++){
		bst.insertNode(arr[i], bst.root);
	}	
//	bst.createMinHightTree(arr, 0, 19, bst.root);
//	bst.displayTree();

	list<TreeNode> *listarr = new list<TreeNode>[100];
	
	bst.createLvlLinkedList(bst.root, 0, listarr);

	displayTreeInLvl(listarr);

//	int treeHeight = bst.getHeight(bst.root, bal);	
	int treeHeight;
	if ( balanced(bst, treeHeight) ){
		cout << "This is a balanced tree, height: " << treeHeight << endl;
	}
	else
		cout << "This is not a balanced tree, height: " << treeHeight << endl;

	delete[] arr;
	delete[] listarr;
	
	return 0;
}
