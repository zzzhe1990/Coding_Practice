#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

class ARRAY{
	private:
		int s;
		int* arra;
		int* arrb;
	public:
		ARRAY(int size):s(size){arra = new int[s]; arrb = new int[s];}
		~ARRAY(){delete[] arra; delete[] arrb;}
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
		arra[i] = rand()%(s*3);
}

void ARRAY::printarr(string str){
	cout << str << ": ";
	for (int i=0; i<s; i++)
		cout << arra[i] << " ";
	cout << endl;
}

void ARRAY::rotarr(int offset){
//	int idx = 0, next;
//	int tmpa = arr[idx], tmpb;
	int next;
	for (int i=0; i<s; i++){
		next = (i + offset) % s;
//		tmpb = arr[next];
//		arr[next] = tmpa;
//		tmpa = tmpb;
//		idx = next;
		arrb[next] = arra[i];
	}
	int* tmp = arra;
	arra = arrb;
	arrb = tmp;
}

void ARRAY::sortarr(bool (*func)(int, int)){
	sort(arra, arra+s, func);
}

int ARRAY::find(int tar, int l, int r){
	int mid = (l+r)/2;
	if (r < l)
		return -1;
	if (arra[mid] == tar)
		return mid;	
	else{
		if (arra[l] < arra[mid]){
			if (arra[l] <= tar && tar <= arra[l])
				return find(tar, l, mid-1);
			else
				return find(tar, mid+1, r);
		}
		else if (arra[l] > arra[mid]){
			if (arra[mid] <= tar && tar <= arra[r])
				return find(tar, mid+1, r);
			else
				return find(tar, l, mid-1);
		}	
		else if (arra[l] == arra[mid]){
			if (arra[mid] != arra[r]){
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
