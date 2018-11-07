#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	string inputStr;
	while (cin >> inputStr) {
		for (int index = (inputStr.length() - 1); index >= 0; --index) {
			cout << inputStr[index];	
		}
		cout << "" << endl;
	}	
}
