template<class T, int MAX_SIZE>
void Digraph::connect(T vval, T eval){
	int i = 0, j = 0;
	while (i<count && adjecents[i].front().value != vval){ 
		i++;
	}
	
	if (i == count){
		cout << "cannot connect because the vertex does not exist." << endl;
		exit(-1);
	}
	
	while (j<count && adjecents[j].front().value != eval){
		j++;
	}
	
	if (j == count){
		cout << "cannot connect because the vertex does not exist." << endl;
		exit(-1);
	}

	adjecents[i].push_back(GraphNode<int, MAX_SIZE>(eval, j));
}

template<class T, int MAX_SIZE>
void Digraph::insert(GraphNode<T, max_size> v){
	int j = 0;
	while (j<v.index && adjecents[j].front().value != v.value){ 
		j++;
	}
	
	if (j < i){
		cout << "the vertex already exists." << endl;
		exit(-1);
	}

	adjecents[v.index].push_back(v);
}

