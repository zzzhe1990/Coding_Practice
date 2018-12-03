#ifndef _CLASS_H
#define _CLASS_H
#include <list>
#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

template<class T, int max_size>
class GraphNode{
	public:
		T value;
		int index;
		bool visited;

		GraphNode(T input):value(input), index(max_size), visited(false){
		}
		GraphNode(T input, int a):value(input), index(a), visited(false){
		}
};

template<class T, int max_size>
class Digraph{
	public:
		int count;
		list< GraphNode<T, max_size> > adjecents[max_size];
		Digraph(int num):count(num){}
		void insert(GraphNode<T, max_size> v);
		void edge(T vval, T eval);
		void display();
		void DFS(GraphNode<T, max_size> r, vector<GraphNode<T, max_size>> &q);
		void BFS(GraphNode<T, max_size> r);
};

template<class T, int max_size>
void Digraph<T, max_size>::DFS(GraphNode<T, max_size> r, vector<GraphNode<T, max_size>> &q){
	typename list<GraphNode<T, max_size>>::iterator itr;
	if (adjecents[r.index].begin() == adjecents[r.index].end())
		return;
	q.push_back(r);
	adjecents[r.index].front().visited = true;
	itr = adjecents[r.index].begin();
	for (itr++; itr != adjecents[r.index].end(); itr++){
		GraphNode<T, max_size> &next = adjecents[itr->index].front();
		if (next.visited == false)
			DFS(next, q);
	}
}

template<class T, int max_size>
void Digraph<T, max_size>::edge(T vval, T eval){
	int i = 0, j = 0;
	while (i<count && adjecents[i].front().value != vval){ 
		i++;
	}
	
	if (i == count){
		cout << "cannot edge because the vertex does not exist." << endl;
		exit(-1);
	}
	
	while (j<count && adjecents[j].front().value != eval){
		j++;
	}
	
	if (j == count){
		cout << "cannot edge because the vertex does not exist." << endl;
		exit(-1);
	}

	adjecents[i].push_back(GraphNode<int, max_size>(eval, j));
}

template<class T, int max_size>
void Digraph<T, max_size>::insert(GraphNode<T, max_size> v){
	int j = 0;
	while (j<v.index && adjecents[j].front().value != v.value){ 
		j++;
	}
	
	if (j < v.index){
		cout << "the vertex already exists." << endl;
		exit(-1);
	}

	adjecents[v.index].push_back(v);
}

template<class T, int max_size>
void Digraph<T, max_size>::display(){
	for (int i = 0; i < count; i++){
		typename list <GraphNode<T, max_size> > :: iterator itr;

		for (itr = adjecents[i].begin(); itr != adjecents[i].end(); itr++)
			cout << itr->value << "-->";
		
		cout << "NULL" << endl;
	}
}

#endif
























