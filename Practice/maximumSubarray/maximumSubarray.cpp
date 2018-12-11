#include <iostream>
#include <vector> /* vector */
#include <cmath> /* max */
#include <climit> /* INT_MIN */

using namespace std;

class Solution {
public:
	int maximumSubarray(vector<int>& input);
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> input{-2,1,-3,4,-1,2,1,-5,4};
	vector<int> input1{-2,1};
	cout << s.maximumSubarray(input1) << endl;
	return 0;
}

int Solution::maximumSubarray(vector<int>& input) {
	int sum = 0;
	/* 这里使用INT_MIN来初始化,可以准确处理第一个元素 */
	int largest_sum = INT_MIN;
	int input_size = input.size();
	for (int input_index=0; input_index < input_size; ++input_index) {
		/* 首先判断之前的sum是否小于0,如果小于0说明可以舍弃之前的计算结果 */
		/* 并重置sum的值为0,重新开始计算 */
		if (sum <=0 ) sum=0;		
		/* 对sum进行累加 */
		sum += input[input_index];
		/* 保存之前的sum中的最大值 */
		largest_sum = max(largest_sum, sum);
	}
	return largest_sum;
}
