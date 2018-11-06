#include <iostream>
#include <math.h> /* round */

using namespace std;

int main(int argc, char *argv[]) {
	double inputDouble;
	while (cin >> inputDouble) {
		/* 直接使用math中的round函数来完成这个功能 */
		cout << (int)round(inputDouble) << endl;
	}
	return 0;
}
