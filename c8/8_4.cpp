#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SET{
	public:
		int* list;
		SET(int s):size(s){list = new int[s];}
		~SET(){delete[] list;}
		int s(){return size;}
		void print();
	private:
		int size;
};

void SET::print(){
	cout << "[";
	for (int i=0; i<size; i++)
		cout << list[i] << " ";
	cout << "]" << endl;
}

void subset(int* arr, int end, vector<SET*> &allsets){
	if (end < 0){
		SET* tmp = new SET(1);
		tmp->list[0] = -1;
		allsets.push_back(tmp);
	}
	else{
		subset(arr, end-1, allsets);
/*		vector<SET*>::iterator itr = allsets.begin();
		vector<SET*>::iterator itrend = allsets.end();
		for (; itr != itrend; itr++){
			SET* tmp = new SET((*itr)->s() + 1);
			for (int i=0; i<(*itr)->s(); i++){
				tmp->list[i] = (*itr)->list[i];
			}	
			tmp->list[(*itr)->s()] = arr[end];
			allsets.push_back(tmp);
*/
		int tmpsize = allsets.size();
		for (int j = 0; j < tmpsize; j++){
			SET* tmp = new SET(allsets[j]->s() + 1);
			for (int i=0; i<allsets[j]->s(); i++){
				tmp->list[i] = allsets[j]->list[i];
			}	
			tmp->list[allsets[j]->s()] = arr[end];
			allsets.push_back(tmp);
		}
	}
}

void printset(vector<SET*> &allsets){
	cout << "All subsets: ";
	for (int i=0; i<allsets.size(); i++){
		allsets[i]->print();
		cout << ", ";
	}
}

int main(int argc, char* argv[]){
	if (argc != 2){
		cout << "Error: invalid environment variables."<<endl;
		exit(EXIT_FAILURE);
	}

	string str(argv[1]);
	int size = stoi(str);
	int* arr = new int[size];
	cout << "init set: [";
	for (int i=0; i<size; i++){
		arr[i] = rand()%(size+size);
		cout << arr[i] << " ";
	}
	cout << "]" << endl;

	vector<SET*> allsets;

	subset(arr, size-1, allsets);	

	printset(allsets);

	delete[] arr;
	
	return 0;
}
