#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int value[5] = {9, 6, 1, 4, 1};
int volume[5] = {4, 3, 5, 2, 5};

int value1[4] = {20, 6, 20, 4};
int volume1[4] = {4, 3, 4, 2};

int value2[5] = {6, 3, 5, 4, 6};
int volume2[5] = {2, 2, 6, 5, 4};

class Knapsack {
public:
	int maxValueRecursive(int number, int capacity);
	int maxValueDynamicPro(int number, int capacity);
};

int main(int argc, char *argv[]) {
	Knapsack kk;
	int current_capacity = 9;
	int total_number = 4;
	// cout << kk.maxValueRecursive(total_number, current_capacity) << endl;
	cout << kk.maxValueDynamicPro(total_number, current_capacity) << endl;
	return 0;
}

int Knapsack::maxValueDynamicPro(int number, int capacity) {
	int **maxValue = new int *[number+1];
	for (int row = 0; row < number+1; ++row) {
		maxValue[row] = new int[capacity+1]();
	}
	/* 遍历获取当totalNum为1...number时,各自的最优解 */
	for (int totalNum = 1; totalNum <= number; ++totalNum) {
		/* 在固定的totalNum前提下,遍历不同的capacity并保存最优解 */
		for (int cap = 1; cap <= capacity; ++cap) {
			if (cap >= volume1[totalNum-1]) {
				maxValue[totalNum][cap] = max(maxValue[totalNum-1][cap], maxValue[totalNum-1][cap-volume1[totalNum-1]] + value1[totalNum-1]);
			}
		} 
	}
	return maxValue[number][capacity];
}

int Knapsack::maxValueRecursive(int number, int capacity) {
	if (number == 0) return 0;
	if (capacity-volume2[number-1] >= 0) {
		return max(maxValueRecursive(number-1, capacity), maxValueRecursive(number-1, capacity-volume2[number-1]) + value2[number-1] );	
	} else {
		return maxValueRecursive(number-1, capacity);	
	}
}
