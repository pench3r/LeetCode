#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	string targetStr;
	char wantChar;
	while (cin >> targetStr >> wantChar) {
		int strFlagArray[128] = {0};
		char currentChar;
		/* 如果为大写字母就转化为小写字母 */
		wantChar = (wantChar >= 'A' && wantChar <= 'Z') ? wantChar + 32 : wantChar;
		for (int strIndex=0; strIndex < targetStr.length(); ++strIndex) {
			currentChar = targetStr[strIndex];
			/* 同样将当前遍历到的字符转化为对应的小写字母 */
			currentChar = (currentChar >= 'A' && currentChar <= 'Z') ? currentChar + 32 : currentChar;
			/* 在标记数组中保存的都是对应字符的小写字符出现的次数 */
			strFlagArray[currentChar]++;
		}
		cout << strFlagArray[wantChar] << endl;
	}
	return 0;
}
