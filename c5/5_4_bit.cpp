#include "bit.h"

void check(int a, int len, int &pivot, int &trails, int cmp){
	while ( (a & 1) == cmp){
		a = a >> 1;
		pivot++;
	}
	while ( (a & 1) != cmp){
		a = a >> 1;
		trails++;
		pivot++;
	}
}


int nextSmallest(int a, int len){
	int pivot = 0;
	int low1s = 0;

	check(a, len, pivot, low1s,  0);	
	
	//flip the pivot bit, then mask the 1's on the right of pivot
	a = a | (1 << pivot);
	a = a & ( ~((1 << pivot) - 1) );
	
	a = a | ((1 << (low1s-1)) - 1);
	
	return a;		
}

int prevLargest(int a, int len){
	int pivot = 0;
	int low0s = 0;
	
	check(a, len, pivot, low0s, 1);
	int low1s = pivot-low0s;
	
	//replace pivot with 0 then mask the 1's on right of pivot
	a = a & ~(1 << pivot);
	a = a & (~( (1 << pivot) -1));
	
	a = a | ( ((1 << (low1s+1)) - 1) << (pivot-low1s-1)	);
	
	return a;
}


int main(int ac, char* av[]){
	int a;
	if (ac <= 1){
		cout << "missing environment argument." << endl;
		exit(EXIT_FAILURE);	
	}
	a = stoi(av[1]);
	int alen = len(a);
	cout << "input integer with " << alen << " bits is: " ;
	printBits(a, alen);

	int ns = nextSmallest(a, alen);
	cout << "next smallest integers is: ";
	printBits(ns, alen);

	int pl = prevLargest(a, alen);
	cout << "previous largest integer is: ";
	printBits(pl, alen);

	return 0;
}
