#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	string inputStr;
	while (cin >> inputStr) {
		int charNumArray[128] = {0};
		for (int index = 0; index < inputStr.length(); ++index) {
			/* 题目的要求统计不同字符的个数 */
			/* 同样使用数组标记来解决这个问题 */
			charNumArray[inputStr[index]] = 1;
		}
		int sum = 0;
		for (int index = 0; index < 128; ++index) {
			sum += charNumArray[index];
		}
		cout << sum << endl;
	}
	return 0;
}
