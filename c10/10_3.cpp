#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

class ARRAY{
	private:
		int s;
		int* arr;
	public:
		ARRAY(int size):s(size){arr = new int[s];}
		~ARRAY(){delete[] arr;}
		void create();
		void printarr(string s);
		void rotarr(int offset);
		void sortarr(bool (*func)(int, int));
		int find(int tar, int l, int r);
};

bool func(int a, int b){return a<b;}

void ARRAY::create(){
//	srand(time(NULL));
	for (int i=0; i<s; i++)
		arr[i] = rand()%(s*3);
}

void ARRAY::printarr(string str){
	cout << str << ": ";
	for (int i=0; i<s; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void ARRAY::rotarr(int offset){
	int idx = 0, next;
	int tmpa = arr[idx], tmpb;
	for (int i=0; i<s; i++){
		next = (idx + offset) % s;
		tmpb = arr[next];
		arr[next] = tmpa;
		tmpa = tmpb;
		idx = next;
	}
}

void ARRAY::sortarr(bool (*func)(int, int)){
	sort(arr, arr+s, func);
}

int ARRAY::find(int tar, int l, int r){
	int mid = (l+r)/2;
	if (r < l)
		return -1;
	if (arr[mid] == tar)
		return mid;	
	else{
		if (arr[l] < arr[mid]){
			if (arr[l] <= tar && tar <= arr[l])
				return find(tar, l, mid-1);
			else
				return find(tar, mid+1, r);
		}
		else if (arr[l] > arr[mid]){
			if (arr[mid] <= tar && tar <= arr[r])
				return find(tar, mid+1, r);
			else
				return find(tar, l, mid-1);
		}	
		else if (arr[l] == arr[mid]){
			if (arr[mid] != arr[r]){
				return find(tar, mid+1, r);
			}
			else{
				int result = find(tar, l, mid-1);
				if (result == -1)
					result = find(tar, mid+1, r);
				return result;
			}
		}
	}
}

int main(int argc, char* argv[]){
	if (argc != 3){
		cout << "error: invalid environment variables." << endl;
		exit(EXIT_FAILURE);
	}
	
//	srand(time(NULL));
	string str1(argv[1]);
	string str2(argv[2]);
	int s = stoi(str1);
	int tar = stoi(str2);
	ARRAY* code = new ARRAY(s);
	code->create();
	code->sortarr(func);
	code->printarr("original");

//	int offset = rand()%s;
	int offset = 4;
	cout << "offset: " << offset << endl;
	code->rotarr(offset);	
	code->printarr("rot");

	cout << "index of " << tar << " is " << code->find(tar, 0, s-1) << endl;	
		

	return 0;
}
