#include <iostream>
#include "designClass.h"
const int MAX_SIZE = 100;

bool ifConnected(Digraph<int, MAX_SIZE> &c4, GraphNode<int, MAX_SIZE> v1, GraphNode<int, MAX_SIZE> v2){
	vector<GraphNode<int, MAX_SIZE>> q;
	q.clear();
		
	c4.DFS(GraphNode<int, MAX_SIZE>(v1.value, v2.index), q);	

	vector<GraphNode<int, MAX_SIZE>>::iterator itr;
	
	for(itr = q.begin(); itr != q.end(); itr++){
		if (itr->value == v2.value){
			return true;
		}
	}
	return false;
}

int main(int argc, char**argv){
	int nodeCount = 5;
	Digraph<int, MAX_SIZE> c4(nodeCount);
	
	for (int i=0; i<nodeCount; i++)
		c4.insert(GraphNode<int, MAX_SIZE>(i, i));
	
	c4.edge(0, 1);		
	c4.edge(0, 2);		
	c4.edge(1, 2);		
	c4.edge(1, 3);		
	c4.edge(3, 0);		
	c4.edge(3, 1);		
	c4.edge(3, 2);		

	c4.display();

	vector<GraphNode<int, MAX_SIZE>> q;

	q.clear();	
	c4.DFS(GraphNode<int, MAX_SIZE>(1, 1), q);	
	
	vector<GraphNode<int, MAX_SIZE>>::iterator itr;
	
	for(itr = q.begin(); itr != q.end(); itr++){
		cout << itr->value << " ";
	}
	cout << endl;

	q.clear();
	c4.DFS(GraphNode<int, MAX_SIZE>(4, 4), q);
	
	for(itr = q.begin(); itr != q.end(); itr++){
		cout << itr->value << " ";
	}
	cout << endl;
	
	cout << "connection between 1, 4: " << ifConnected(c4, GraphNode<int, MAX_SIZE>(1,1), GraphNode<int, MAX_SIZE>(4,4)) << endl;
	cout << "connection between 1, 3: " <<ifConnected(c4, GraphNode<int, MAX_SIZE>(1,1), GraphNode<int, MAX_SIZE>(3,3)) << endl;
	return 0;
}
