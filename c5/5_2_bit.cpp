#include "bit.h"
#include <string>
#include <sstream>

int main(int argc, char** argv){
	double in = 0.122;
	ostringstream out;
	string str(".");	

	while (in != 0.0){
		if(str.size() > 32){
			cout << "ERROR" << endl;
			break;
		}
		in *= 2;
		if (in >= 1.0){
			in -= 1.0;
			str.append("1");	
		}
		else{
			str.append("0");
		}
	}
	cout << "binary representation: " << str << endl;
}

