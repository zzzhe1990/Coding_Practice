#include <iostream>
#include <string>

using namespace std;

int product(int small, int large){
	if (small == 0) return 0;
	if (small == 1) return large;
	int p;
	int res = small % 2;
	if (res == 0){
		p = product(small>>1, large) << 1;	
	}	
	else{
		p = (product(small>>1, large) << 1) + large;
	}
	return p;
}

int main(int argc, char* argv[]){
	if (argc !=3 ){
		cout << "error: invalid environment variables." << endl;
		exit(EXIT_FAILURE);	
	}
	string str1(argv[1]), str2(argv[2]);
	int a = stoi(str1);
	int b = stoi(str2);
	if (a<=0 || b<=0){
		cout << "error: environment variables must be positive integers." << endl;
		exit(EXIT_FAILURE);
	}

	int small = (a < b? a:b);
	int large = (a > b? a:b);

	int p = product(small, large);

	cout << "product: " << p << endl;

	return 0;
}
