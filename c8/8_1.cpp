#include <iostream>
#include <string>
using namespace std;

int hop(int leftstep, int* arr){
	if (leftstep == 0)
		return 1;
	else if (leftstep < 0)
		return 0;
	
	if (arr[leftstep] == 0)
		arr[leftstep] = hop(leftstep-1, arr) + hop(leftstep-2, arr) + hop(leftstep-3, arr);
	
	return arr[leftstep];
}

int main(int argc, char* argv[]){
	if (argc != 2){
		cout << "missing environmental variable." << endl;
		exit(0);
	}
	
	string arg = argv[1];
	size_t pos;
	int x = stoi(arg, &pos);
	
	int* arr = new int[x+1];
	for (int i=0; i<=x; i++)
		arr[i] = 0;
	
	cout << "There are " << hop(x, arr) << " possible ways to run up " << x << " steps stair." << endl;


	delete[] arr;

	return 0;
}
