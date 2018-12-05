#include <iostream>
#include "tree.h"

using namespace std;

int main(){
	int* arr = new int[15];
	Tree bst;

	for (int i=0; i<15; i++){
		arr[i] = i;
//		bst.insertNode(treeArray[i], bst.root);
	}

	bst.createMinHightTree(arr, 0, 14, bst.root);
	bst.displayTree();
	
	delete[] arr;
	
	return 0;
}
