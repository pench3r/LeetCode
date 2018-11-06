#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string numberReverse(string inputStr);
void numberReverseBeta(int inputNum);

int main(int argc, char *argv[]) {
	int inputNumStr;
	while (cin >> inputNumStr) {
		// cout << numberReverse(inputNumStr) << endl;
		numberReverseBeta(inputNumStr);
	}
	return 0;
}

void numberReverseBeta(int inputNum) {
	char tmp;
	while (inputNum) {
		/* 获取各位数的字符 */
		tmp = inputNum % 10 + '0';
		/* 输出获取到的最右边的数字,相当与reverse */
		cout << tmp;
		/* 将整个数字右移 */
		inputNum /= 10;
	}
	cout << "" << endl;
}

string numberReverse(string inputStr) {
	/* 题目的意思是reverse所有,一开始理解为只要有零才reverse */
	// if (inputStr.find('0') == string::npos) return inputStr;
	std::reverse(inputStr.begin(), inputStr.end());
	return inputStr;
}
