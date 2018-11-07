#include <iostream>

using namespace std;


int main(int argc, char *argv[]) {
	int totalNum;
	while (cin >> totalNum) {
		int inputTable[1000] = {-1};
		int key_input;
		int value_input;
		while (totalNum--) {
			cin >> key_input >> value_input;
			/* 这里使用数组来记录每个key对应值的累加结果 */
			inputTable[key_input] += value_input;
		}
		for (int i = 0; i < 1000; ++i) {
			/* 判断key对应的值是否为初始化的默认值 */
			if (inputTable[i] != -1) {
				cout << i << " " <<  inputTable[i] << endl;
			}
		}
	}
	return 0;
}
