#include "bit.h"

int getBit(int num, int idx){
	int tmp = num & (1<<idx);
	if(tmp != 0)
		return 1;
	else
		return 0;
}

int setBit(int num, int idx){
	return (1<<idx) | num;	
}

int clearBit(int num, int idx){
	int mask = ~(1<<idx);
	return num & mask;
}

int updateBit(int num, int idx, bool isBit1){
	int v = isBit1 ? 1 : 0;
	int mask = ~(1 << idx);

	return (num & mask) | (v << idx);
}

void printBits(int num, int size){
	for (int i=size-1; i>=0; i--){
		cout << getBit(num, i);
	}
	cout << endl;
/*
	stack<int> s;
	int mod;
	while(num != 0){
		mod = num % 2;
		s.push(mod);
		num /= 2;		
	}
	
	while (!s.empty()){
		cout << s.top();
		s.pop();
	}
	cout << endl;
*/
}

int len(int num){
	int len = 0;
	while (num > 0){
		num = num / 2;
		len++;
	}

	return len;
}
