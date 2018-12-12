#include "bit.h"
#include <cmath>

int main(int argc, char* argv[]){
	int a;
	if (argc > 1)
		a = stoi(argv[1]);
	else{
		cout << "missing environment argument." << endl;
		exit(EXIT_FAILURE);
	} 
	
	cout << "input integer binary bits is: ";
	printBits(a, 32);
	
	int prelen = 0, curlen = 0;
	int maxlen = 0;
	for(int i=0; i<32; i++){
		if ( (a & 1) != 0){
			curlen++;
			a = a >> 1;
			maxlen = max(maxlen, prelen+curlen);
		}
		else{
			if ( (a & (1<<1)) != 0){
				prelen = curlen+1;	
				curlen = 0;
				a = a >> 1;
			}
			else{
				maxlen = max(maxlen, curlen+1);
				curlen = 0;
				a = a >> 1;
			}
		}
		
	}
	cout << "The longest sequence of 1's: " << maxlen << endl;

	return 0;
}
