#include <iostream>

using namespace std;

/* 更快的一种方式是通过统计相关的数据,得出的结论是可以喝到的饮料为 */
/* bottleNum / 2 这种是最快捷的 */
static int maxSodaBottle(int bottleNum);

int main(int argc, char *argv[]) {
	int input;
	while (cin >> input) {
		if (input == 0) continue;
		cout << maxSodaBottle(input) << endl;
	}
	return 0;
}

/* 该实现方法为递归算法 */
static int maxSodaBottle(int bottleNum) {
	int quotient = bottleNum / 3;
	int remainder = bottleNum % 3;
	if (bottleNum < 2) return 0;
	if (bottleNum == 2) return 1;
	return quotient + maxSodaBottle(quotient + remainder);
}
