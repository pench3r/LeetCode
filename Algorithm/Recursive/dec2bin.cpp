#include <iostream>
#include <vector>

using namespace std;

static void dec2bin(int number, vector<int> &result);

int main(int argc, char *argv[]) {
	vector<int> result;
	dec2bin(1389, result);
	for (int index = (result.size()-1); index >= 0; --index) {
		cout << result[index];
	}
	return 0;
}

static void dec2bin(int number, vector<int> &result) {
	int quotient = number / 2;
	int remainder = number % 2;
	result.push_back(remainder);
	if (quotient > 0) {
		dec2bin(quotient, result);
	}
}
