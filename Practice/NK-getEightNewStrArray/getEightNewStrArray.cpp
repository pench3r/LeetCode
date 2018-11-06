#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getEightNewStrArray(vector<string> &output, string input);

int main(int argc, char *argv[]) {
	string inputStr1, inputStr2;
	vector<string> outStrVec;
	while (cin >> inputStr1 >> inputStr2) {
		getEightNewStrArray(outStrVec, inputStr1);
		getEightNewStrArray(outStrVec, inputStr2);
		for (int index = 0; index < outStrVec.size(); ++index) {
			cout << outStrVec[index] << endl;
		}
	}
	return 0;
}

void getEightNewStrArray(vector<string> &output, string input) {
		/* 如果字符的长度超过8,就开始循环切割处理 */
		while (input.length() / 8) {
			output.push_back(input.substr(0, 8));	
			input = input.substr(8);
		}
		/* 当字符串长度等于0时,就不需要再做处理,直接返回 */
		if (input.length() == 0) return;
		/* 当字符长度不够8时,开始补零处理 */
		input.append(8-input.length(), '0');
		output.push_back(input);
}
