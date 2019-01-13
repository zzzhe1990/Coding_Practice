#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void merge(int* a, int* b, int s1, int s2){
	int aidx = s1-1;
	int bidx = s2-1;
	int idx = s1+s2-1;
	
	while (aidx >= 0 || bidx >= 0){
		if (a[aidx] >= b[bidx]){
			a[idx] = a[aidx];
			aidx--;
		}
		else{
			a[idx] = b[bidx];
			bidx--;
		}
		idx--;
	}	
	if (aidx < 0){
		for (int i=0; i<=bidx; i++){
			a[bidx] = b[bidx];
		}
	}	
}

void print(int* arr, int s, string str){
	cout << str << ": ";
	for (int i=0; i<s; i++)
		cout << arr[i] << " ";
	cout << endl;
}

bool func(int a, int b){return a<b;}

int main(){
	int s1 = 10, s2 = 15;
	int* a = new int[s1+s2];
	int* b = new int[s2];
	
	for (int i=0; i<s1; i++)
		a[i] = rand()%100;
	for (int i=0; i<s2; i++)
		b[i] = rand()%100;

	sort(a, a+s1, func);
	sort(b, b+s2, func);
	
	print(a, s1, "s1");
	print(b, s2, "s2");

	merge(a, b, s1, s2);
	print(a, s1+s2, "s1");
	
	delete[] a;
	delete[] b;

	return 0;
}
