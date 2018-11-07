#include <iostream>

using namespace std;

int main(int agc, char *argv[]) {
	string inputStr;
	while (cin >> inputStr) {
		int store[128] = {0};
		for (int index = 0; index < inputStr.length(); ++index) {
			/* 使用数组来保存每个key(对应字符)出现的次数 */
			store[inputStr[index]]++;
		}
		int currentCharNum = 0;
		for (int index = 0; index < 128; ++index) {
			currentCharNum = store[index];	
			if (currentCharNum == 0) continue;
			/* 通过遍历每个key对应的次数来输出 */
			for (int j = 0; j < currentCharNum; ++j) {
				cout << char(index);
			}
		}
		cout << "" << endl;
	}	
	return 0;
}
