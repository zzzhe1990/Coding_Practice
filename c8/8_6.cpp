#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool safe(int bottom, int top){
	return (top < bottom);
}

void move(stack<int> &s, stack<int> &d){
	d.push(s.top());
	s.pop();
}

void hanoi_exe(stack<int> &s1, stack<int> &s2, stack<int> &s3, int size){
	if (size == 1)
		move(s1, s3);
/*	else if(size == 2){
		move(s1, s3);
		move(s1, s2);
		move(s3, s1);
		move(s2, s3);
		move(s1, s3);
	}
*/	else{
		hanoi_exe(s1, s2, s3, size-1);	
		move(s1, s2);
		hanoi_exe(s3, s2, s1, size-1);
		move(s2, s3);
		hanoi_exe(s1, s2, s3, size-1);
	}
}

void hanoi(stack<int> &s1, stack<int> &s2, stack<int> &s3){
	hanoi_exe(s1, s2, s3, s1.size());	
}

void printstacks(stack<int> &s1, stack<int> &s2, stack<int> &s3){
	cout << "s1: ";
	int size = s1.size();
	for (int i=0; i<size; i++){
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;
	size = s2.size();
	cout << "s2: ";
	for (int i=0; i<size; i++){
		cout << s2.top() << " ";
		s2.pop();
	}
	cout << endl;
	size = s3.size();
	cout << "s3: ";
	for (int i=0; i<size; i++){
		cout << s3.top() << " ";
		s3.pop();
	}
	cout << endl;
}

int main(){
	stack<int> s1;
	stack<int> s2;
	stack<int> s3;

	for (int i = 8; i > 0; i--)
		s1.push(i);
	
	hanoi(s1, s2, s3);

	printstacks(s1, s2, s3);	

	return 0;
}
