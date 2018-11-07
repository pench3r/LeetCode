#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	string input;
	int charNum;
	while (cin>>input>>charNum) {
		int inputFlag[100] = {0};
		int index = 0;
		while ( index < input.length()) {
			/* 这里判断当前字符ascii是否小于0 */
			if ((int)input[index] < 0) {
				inputFlag[index] = 1;
				/* 因为内存中中文是3个长度 */
				index += 3;
				continue;
			}
			index++;
		}
		/* 判断当前字符所处的位置是否为中文的头部和中部 */
		if (inputFlag[charNum-1] == 1 || inputFlag[charNum-2] == 1) {
			cout << input.substr(0, charNum-1) << endl;;
			continue;
		}	
		cout << input.substr(0, charNum) << endl;
	}
	return 0;
}
