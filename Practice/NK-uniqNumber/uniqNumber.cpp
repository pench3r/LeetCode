#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	string inputNum;
	while (cin >> inputNum) {
		int numArray[10] = {0};		
		for (int index = 0; index < inputNum.length(); ++index) {
			numArray[inputNum[index]] = 1;
		}
		for (int index = (inputNum.length() - 1); index >= 0; --index) {
			/* 使用标记数组进行字符的记录 */
			if (numArray[inputNum[index]]) {
				cout << inputNum[index];
				/* 对于已经输出的字符去除对应的标记 */
				numArray[inputNum[index]] = 0;
			}
		}
		cout << "" << endl;
	}
	return 0;
}
