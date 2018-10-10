#include <iostream>
#include <vector> /* vector */
#include <set> /* set */

using namespace std;

class Solution {
public:
	void setMatrixZero(vector<vector<int>>& matrix);
	void setMatrixZeroBeta(vector<vector<int>>& matrix);
};

int main(int argc, char *argv[]) {
	vector<vector<int>> matrix{{1,1,1},{1,0,1},{1,1,1}};
	vector<vector<int>> matrix1{{0,1,2,0},{3,4,5,2},{1,3,1,5}};
	Solution s;
	s.setMatrixZero(matrix1);
	s.setMatrixZeroBeta(matrix);
	return 0;
}

void Solution::setMatrixZeroBeta(vector<vector<int>>& matrix) {
	/* store first row and first col state */
	size_t rowCount = matrix.size();
	size_t colCount = matrix[0].size();		
	bool row = false;
	bool col = false;
	/* store first row state */
	for (int colIndex=0; colIndex < colCount; ++colIndex) {
		if (matrix[0][colIndex] == 0) {
			row = true;
			break;
		}	
	}	

	/* store first col state */
	for (int rowIndex=0; rowIndex < rowCount; ++rowIndex) {
		if (matrix[rowIndex][0] == 0) {
			col = true;
			break;
		}
	}
	/* update [0][0] */
	matrix[0][0] = row || col ? 0 : matrix[0][0];

	/* update first col and first row */
	/* begin to second row */
	for (int colIndex=1; colIndex < colCount; ++colIndex) {
		for (int rowIndex=1; rowIndex < rowCount; ++rowIndex) {
			if (matrix[rowIndex][colIndex] == 0) {
				matrix[0][colIndex] = 0;
				matrix[rowIndex][0] = 0;
			}
		}
	} 

	/* update row and col from first col and first row */
	for (int colIndex=1; colIndex < colCount; ++colIndex) {
		if (matrix[0][colIndex] == 0) {
			for (int rowIndex=1; rowIndex < rowCount; ++rowIndex) {
				matrix[rowIndex][colIndex] = 0;
			}
		}
		/* update first row */
		if (row) {
			matrix[0][colIndex] = 0;
		}
	}

	for (int rowIndex=1; rowIndex < rowCount; ++rowIndex) {
		if (matrix[rowIndex][0] == 0) {
			for (int colIndex=1; colIndex < colCount; ++colIndex) {
				matrix[rowIndex][colIndex] = 0;
			}
		}
		/* update first col */
		if (col) {
			matrix[rowIndex][0] = 0;
		}
	}

}

void Solution::setMatrixZero(vector<vector<int>>& matrix) {
	size_t m = matrix.size();
	size_t n = matrix[0].size();
	set<int> rowStack;
	set<int> colStack;
	size_t row = -1;
	size_t col = -1;
	for (int rowIndex=0; rowIndex < m; ++rowIndex) {
		for (int colIndex=0; colIndex < n; ++colIndex) {
			if (matrix[rowIndex][colIndex] == 0) {
				if(rowStack.find(rowIndex) == rowStack.end()) {
					rowStack.insert(rowIndex);
				}		
				if(colStack.find(colIndex) == colStack.end()) {
					colStack.insert(colIndex);
				}		
			}
		}
	}
	set<int>::iterator it;
	/* update row of matrix */
	for (it = rowStack.begin(); it != rowStack.end(); ++it) {
		for (int colIndex = 0; colIndex < n; ++colIndex) {
			matrix[*it][colIndex] = 0;
		}	
	}	
	/* update col of matrix */
	for (it = colStack.begin(); it != colStack.end(); ++it) {
		for (int rowIndex = 0; rowIndex < m; ++rowIndex) {
			matrix[rowIndex][*it] = 0;
		}
	}

	/* print matrix */
	for (int rowIndex=0; rowIndex < m; ++rowIndex) {
		for (int colIndex=0; colIndex < n; ++colIndex) {
			cout << matrix[rowIndex][colIndex] << " ";
		}
		cout << "\n";
	}
}
