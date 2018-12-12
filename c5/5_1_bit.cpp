#include "bit.h"

int updateBits(int M, int N, int i, int j){
	int mask = -1;
	mask = mask << j;
	mask = mask | ((1 << i) - 1);

	N = N & mask;
	int tmp = M << i;
	N = N | tmp;

	return N;
}

int main(int argc, char** argv){
	int M, N;
	M = atoi(argv[1]);
	N = atoi(argv[2]);	
	
	cout << "M: ";
	printBits(M, 32);	
	cout << "N: ";
	printBits(N, 32);
	cout << "INT_MAX: ";
	printBits(INT_MAX, 32);

	int i = 2;
	int j = 6;

	int merge = updateBits(M, N, i, j);
	cout << "merge M to N: ";
	printBits(merge, 32);

	return 0;
}
