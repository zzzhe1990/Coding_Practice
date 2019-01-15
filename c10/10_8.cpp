#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class BITSET(){
	private:
		int s;
		int* arr;
	public:
		BITSET(int size):s(size){arr = new int[size/sizeof(int) + 1]; }
		~BITSET(){delete[] arr; }
		int get(int idx);
		void set(int idx);
		void clear(int idx);
};

int BITSET::get(int idx){
	int int_idx = (idx >> 5);
	int in_int_idx = (idx & 0x1F);
	int tmp = arr[int_idx];
	return (tmp & (1<<in_int_idx) != 0);
}

void BITSET::set(int idx){
	int int_idx = (idx >> 5);
	int in_int_idx = (idx & 0x1F);
	arr[int_idx] = (arr[int_idx] | (1 << in_int_idx));
}

void BITSET::clear(int idx){
	int int_idx = (idx >> 5);
	int in_int_idx = (idx & 0x1F);
	arr[int_idx] = (arr[int_idx] & ~(1 << in_int_idx));
}

int main(int argc, char* argv[]){
	if (argc != 2){
		cout << "error: invalid environment variables" << endl;
		exit(EXIT_FAILURE);
	}
	srand(time(NULL));

	int* arr = new int[40000];

	return 0;
}
