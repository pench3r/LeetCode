#include <iostream>
#include <vector> /* vector */

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board);
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<vector<char>> board{{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},	
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}};	
	vector<vector<char>> board1{
		{'8','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};
	vector<vector<char>> board2{
		{'.','.','4','.','.','.','6','3','.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'5','.','.','.','.','.','.','9','.'},
		{'.','.','.','5','6','.','.','.','.'},
		{'4','.','3','.','.','.','.','.','1'},
		{'.','.','.','7','.','.','.','.','.'},
		{'.','.','.','5','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.'}
	};
	vector<vector<char>> board3{
		{'8','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}	
	};
	cout << s.isValidSudoku(board3) << endl;
	return 0;
}

bool Solution::isValidSudoku(vector<vector<char>>& board) {
	/* 分别保存行、列、矩阵的标记 */
	unsigned int rowFlag[9] = {0};
	unsigned int colFlag[9] = {0};
	unsigned int matrixFlag[9] = {0};
	int rowCount = board.size();
	int colCount = board[0].size();
	for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
		for (int colIndex = 0; colIndex < colCount; ++colIndex) {
			/* 先提取对应的元素，判断是否为'.' */
			char element = board[rowIndex][colIndex];
			if (element == '.') continue;
			int elementValue = element - '0';
			/* 判断对应行中是否存在对应的值,没有就保存对应的值 */
			if (((rowFlag[rowIndex] >> elementValue) & 1) == 0) {
				rowFlag[rowIndex] = rowFlag[rowIndex] | (1 << elementValue);	
			} else {
				return false;
			}
			/* 判断对应列中是否存在对应的值 */
			if (((colFlag[colIndex] >> elementValue) & 1) == 0) {
				colFlag[colIndex] = colFlag[colIndex] | (1 << elementValue);
			} else {
				return false;
			}
			/* 判断对应的matrix中是否存在对应的值 */
			int matrixIndex = (rowIndex / 3)*3 + colIndex / 3;
			if (((matrixFlag[matrixIndex] >> elementValue) & 1) == 0) {
				matrixFlag[matrixIndex] = matrixFlag[matrixIndex] | (1 << elementValue);
			} else {
				return false;
			}
		}
	}	
	return true;
}
