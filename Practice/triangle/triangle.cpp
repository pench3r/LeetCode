#include <iostream>
#include <climits> /* INT_MAX */
#include <vector> /* vector */
#include <cmath> /* min */

using namespace std;

class Solution{
public:
	int minimumTotal(vector<vector<int>>& triangle);
};

int main(int argc, char *argv[]){
	Solution s;
	vector<vector<int>> triangle_input{{2},{3,4},{6,5,7},{4,1,8,3}};
	cout << s.minimumTotal(triangle_input) << endl;
	return 0;
}

int Solution::minimumTotal(vector<vector<int>>& triangle) {
	int minSum = INT_MAX;
	int rowTotal = triangle.size();
	/* 当只有一行时,直接返回该行的值即可 */
	if (rowTotal == 1) return triangle[0][0];
	/* 行数从0开始计算 */
	/* 0行不做处理,第一行开始 */
	for (int rowIndex=1; rowIndex < rowTotal; ++rowIndex) {
		/* 先处理每一行的头和尾 */
		triangle[rowIndex][0] += triangle[rowIndex-1][0];
		triangle[rowIndex][rowIndex] += triangle[rowIndex-1][rowIndex-1];
		/* 这里之前存在bug,后续的比较中忽略了头和尾所以需要在这里进行涉及大小的比较 */
		/* 这里直接比较头尾可以用来初始化minSum */
		minSum = min(triangle[rowIndex][0], triangle[rowIndex][rowIndex]);
		/* 接着处理介于头和尾中间的数值 */
		for (int colIndex=1; colIndex < rowIndex; ++colIndex) {
			/* 更新当前位置的值,获取上一层中与该值相邻的最小值,相邻有2个值 */
			/* 这里的处理确保都为介于头和尾的中间值 */
			/* 处理每一层的数据都会借用上一层的数据索引的范围为colIndex-1和colIndex */
			triangle[rowIndex][colIndex] = min(triangle[rowIndex-1][colIndex-1], triangle[rowIndex-1][colIndex]) + triangle[rowIndex][colIndex];
			/* 如果判定到了最后一层(rowIndex+1==rowTotal),就判断保存最小的路径和 */
			if (rowIndex + 1 == rowTotal) {
				minSum = min(minSum, triangle[rowIndex][colIndex]);
			}
		}
	}
	/* 最后直接返回的即为最终结果 */
	return minSum;
}
