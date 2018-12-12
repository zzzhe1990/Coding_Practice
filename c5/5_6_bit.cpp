#include "bit.h"

int main(int argc, char* argv[]){
	if (argc != 3){
		cout << "incorrect environment arguments." << endl;
		exit(EXIT_FAILURE);
	}
	int m = stoi(argv[1]);
	int n = stoi(argv[2]);
	int mlen = len(m);
	int nlen = len(n);

	cout << "m: ";
	printBits(m, mlen);
	cout << "n: ";
	printBits(n, nlen);
	
	int count = 0;
	for (int c = m^n; c!=0; c = c&(c-1)){
		count++;
	}
	cout << "bits difference: " << count << endl;

	return 0;
}
