#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	string inputStr;
	char currentChar;
	while (getline(cin, inputStr)) {
		int digitalNum = 0;
		int letterNum = 0;
		int spaceNum = 0;
		int miscNum = 0;
		for (int index = 0; index < inputStr.length(); ++index) {
			currentChar = inputStr[index];
			/* 判断当前字符是否为字母 */
			if ((currentChar >= 'A' && currentChar <= 'Z') || (currentChar >= 'a' && currentChar <= 'z')) {
				letterNum++;
				continue;
			}
			/* 判断当前字符是否为空格 */
			if (currentChar == ' ') {
				spaceNum++;
				continue;
			}
			/* 判断当前字符是否为数字 */
			if (currentChar >= '0' && currentChar <= '9') {
				digitalNum++;	
				continue;
			}
			miscNum++;
		}
		cout << letterNum << endl;
		cout << spaceNum << endl;
		cout << digitalNum << endl;
		cout << miscNum << endl;
	}
	return 0;
}
