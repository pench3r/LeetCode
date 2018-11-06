#include <iostream>
#include <string>
#include <map> /* map */

using namespace std;

class Solution {
public:
	int firstUniqueCharInString_map(string input);
	int firstUniqueCharInString_array(string input);
	char firstUniqueCharInString_array_with_senstive(string input, string senstiveFlag);
};

int main(int argc, char *argv[]) {
	Solution s;
	string inputStr("aBaaabcde");
	cout << s.firstUniqueCharInString_array(inputStr) << endl;
	cout << s.firstUniqueCharInString_array_with_senstive(inputStr, "true") << endl;
	return 0;
}

/* 返回对应的字符,可以通过flag来设置大小写敏感 */
char Solution::firstUniqueCharInString_array_with_senstive(string input, string senstiveFlag){
	int eachCharCount[256] = {0};
	int char_pos;
	char current_char;
	for (int index=0; index < input.size(); ++index) {
		current_char = input[index];
		if (senstiveFlag == "false") {
			/* 如果为大写字母转换为小写字母 */
			current_char = (current_char >= 'A' && current_char <= 'Z') ? (current_char + 32) : current_char;
		}
		/* 保存对应字母出现的次数 */
		eachCharCount[current_char]++;
	}
	for (int index=0; index < input.size(); ++index) {
		current_char = input[index];
		if (senstiveFlag == "false") {
			/* 同上 */
			current_char = (current_char >= 'A' && current_char <= 'Z') ? (current_char + 32) : current_char;
		}
		/* 检测当前位置的字符是否只出现过一次 */
		if (eachCharCount[current_char] == 1) {
			/* 无视字符的大小写,返回当前索引输出即可 */
			char_pos = index;
			break;
		}
	}
	return input[char_pos];
}

int Solution::firstUniqueCharInString_array(string input) {
	int eachCharCount[256] = {0};
	for (int index=0; index < input.size(); ++index) {
		eachCharCount[input[index]]++;
	}
	for (int index=0; index < input.size(); ++index) {
		if (eachCharCount[input[index]] == 1) {
			return index;
		}
	}
	return -1;
}

int Solution::firstUniqueCharInString_map(string input) {
	map<char, int> eachCharCount;
	for (int index=0; index < input.size(); ++index) {
		eachCharCount[input[index]]++;
	}
	for (int index=0; index < input.size(); ++index) {
		if (eachCharCount[input[index]] == 1) {
			return index;
		}
	}
	return -1;
}
