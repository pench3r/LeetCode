/* 该题目也可以使用stack,使用top来判断,使用pop来移除数据 */
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	string inputStr;
	vector<string> sentenceVec;
	while (cin >> inputStr) {
		/* 使用vector来保存每个单词 */
		/* 遍历输入保存每个单词 */
		sentenceVec.push_back(inputStr);
	}
	for (int index = sentenceVec.size()-1; index > 0; --index) {
		cout << sentenceVec[index] << " ";
	}
	cout << sentenceVec[0] << endl;
	return 0;
}
