#include <iostream>
#include <string>
#include <cstring>

using namespace std;

static int getLastWordLen(string input);

int main(int argc, char *argv[]) {
	string test;
	/* 获取用户输入并带上空格,只使用cin会失败 */
	getline(cin, test);
	cout << getLastWordLen(test) << endl;
	return 0;
}

static int getLastWordLen(string input) {
	int wordLen = 0;
	/* 先获取原始的最后元素的索引位置 */
	int orgLen = input.length()-1;	
	while (input[orgLen] == ' ') {
		/* 更新索引位置 */
		orgLen--;
	}
	/* 注意substr的第二个参数是表示长度的因此这里需要+1 */
	input = input.substr(0, orgLen+1);
	for (int index = (input.length()-1); index >= 0; --index) {
		if (input[index] == ' ') break;
		wordLen++;
	}
	return wordLen;
}
