#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int inputNum;
	while (cin >> inputNum) {
		int oneNum = 0;
		while ( inputNum) {
			if (inputNum % 2) oneNum++;
			inputNum /= 2;
		}
		cout << oneNum << endl;
	}
	return 0;
}
