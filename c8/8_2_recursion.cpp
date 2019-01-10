#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <unordered_set>
using namespace std;


class GRID{
	public:
		bool** arr;
		GRID(int a, int b, bool v);
		~GRID();
		void block(int i, int j);
		int w(){return x;}
		int h(){return y;}
		void print();
		void connect(int i, int j);
	private:
		int x, y;
		bool value;
};

GRID::GRID(int a, int b, bool v){
	x = a;
	y = b;
	value = v;
	arr = new bool*[y];

	for (int row=0; row<y; row++){
		arr[row] = new bool[x];
	}	
	for (int row=0; row<y; row++)		
		for (int col=0; col<x; col++)
			arr[row][col] = value;
}

GRID::~GRID(){
	for (int row=0; row<y; row++)
		delete[] arr[row];
	delete[] arr;
}

void GRID::block(int r, int c){
	arr[r][c] = false;
}

void GRID::connect(int r, int c){
	arr[r][c] = true;
}

void GRID::print(){
	for (int r=0; r<x; r++){
		for (int c=0; c<y; c++)
			cout << arr[r][c] << " ";
		cout << endl;
	}
	cout << endl;
}

class POINT{
	public:
		int r, c;
		POINT(int a, int b):r(a),c(b){};
		void node();
};

void POINT::node(){
	cout << "[" << r << ", " << c << "] ";
}


bool getPath(int r, int c, list<POINT>* path, GRID* maze, stack<POINT>* pool, unordered_set<POINT>* visited){
	if (r < 0 || c < 0 || !maze->arr[r][c])
		return false;		

	bool isFirst = (r == 0 && c == 0);
	POINT p(r, c);

	if (visited->find(p) == visited->end() )
		return false;

	if (isFirst || getPath(r-1, c, path, maze, pool, visited) || getPath(r, c-1, path, maze, pool, visited)){
		pool->push(p);
		visited->insert(p);
		return true;
	}
	else{
		return false;
	}
}



int main(int argc, char* argv[]){
	if (argc != 3){
		cout << "ERROR: invalid environmental variables." << endl;
		exit(EXIT_FAILURE);
	}	
	string str1(argv[1]), str2(argv[2]);	
	int width = stoi(str1);
	int height = stoi(str2);
	GRID maze(width, height, true);
	
	for (int b=0; b<width*height/5; b++){
		int r = rand()%width;
		int c = rand()%height;
		maze.block(r,c);	
	}
	maze.connect(height-1, width-1);
	
	maze.print();

	list<POINT> path;
//hashset: unordered_set can be used to replace GRID.
	unordered_set<POINT> visited;
	//GRID visited(width, height, false);
	stack<POINT> pool;

	bool isPath = getPath(height-1, width-1, &path, &maze, &pool, &visited);

	cout << "Path between two points: " << isPath << endl;
	
	return 0;
}
























