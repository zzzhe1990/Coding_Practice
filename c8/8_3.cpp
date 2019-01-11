#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool func(int i, int j){
	return (i < j);
}

int search(int* arr, int begin, int end){
	if (begin > end)
		return -1;

	int mid = (end + begin)/2;
	if (mid == arr[mid])
		return mid;

	if (begin <= arr[end] || end >= arr[begin]){
		int leftidx = min(mid-1, arr[mid]);
		int left = search(arr, begin, leftidx);
		if (left > 0)
			return left;		

		int rightidx = max(mid+1, arr[mid]);
		int right =  search(arr, rightidx, end);
		return right;
	}
	return -1;
}

int main(int argc, char* argv[]){
	if (argc !=2 ){
		cout << "error: invalid environment variables." << endl;
		exit(EXIT_FAILURE);
	}
	string str(argv[1]);
	int size = stoi(str);
	int* arr = new int[size];	

	for (int i=0; i<size; i++){
		arr[i] = rand()%(size);
	}

	sort(arr, arr+size, func);
	for (int i=0; i<size; i++)
		cout << arr[i] << " ";
	cout << endl;

	int Hidx = search(arr, 0, size-1);
	cout << "Hidx: " << Hidx << endl;

	return 0;
}
