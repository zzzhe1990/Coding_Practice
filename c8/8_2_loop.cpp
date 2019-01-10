#include <iostream>
using namespace std;

class GRID{
	public:
		int** arr;
		GRID(int a, int b);
		~GRID();
		void block(int i, int j);
		int w(){return x;}
		int h(){return y;}
	private:
		int x, y;
};

GRID::GRID(int a, int b){
	x = a;
	y = b;
	arr = new int*[y];

	for (int i=0; i<y; i++){
		arr[i] = new int[x];
	}	
	for (int i=0; i<y; i++)		
		for (int j=0; j<x; j++)
			arr[i][j] = 1;
}

GRID::~GRID(){
	for (int i=0; i<y; i++)
		delete[] arr[i];
	delete[] arr;
}

void GRID::block(int i, int j){
	arr[i][j] = 0;
//	arr[i * x + j] = 0;
}


void findPath(GRID* table){
	for (int i=0; i<table->h(); i++){
		for (int j=0; j<table->w(); j++){
			if (table->arr[i][j] == 0)
				continue;
			if (i==0 && j==0){
			}
			else if (i == 0)
				table->arr[i][j] = table->arr[i][j-1];
			else if (j == 0)
				table->arr[i][j] = table->arr[i-1][j];
			else
				table->arr[i][j] = table->arr[i][j-1] + table->arr[i-1][j];
		}
	}
}

void printTable(GRID* table){
	for (int i=0; i<table->h(); i++){
		for (int j=0; j<table->w(); j++)
			cout << table->arr[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

int main(){
	GRID table(5, 5);

	for (int i=1; i<4; i++){
		for (int j=2; j<3; j++)
			table.block(i, j);
	}
	
	printTable(&table);

	findPath(&table);

	printTable(&table);	

	return 0;
}
