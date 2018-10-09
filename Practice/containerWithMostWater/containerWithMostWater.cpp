#include <iostream>
#include <vector> /* vector */
#include <algorithm> /* max */

/* 
#define MAX(x,y) (((x) < (y)) ? (y) : (x))
#define MIN(x,y) (((x) < (y)) ? (x) : (y))
*/

using namespace std;

class Solution {
public:
	int containerWithMostWater(vector<int>& input);
};

int main(int argc, char *argv[]) {
	Solution s;
	vector<int> input{1,8,6,2,5,4,8,3,7};
	cout << s.containerWithMostWater(input) << endl;
	return 0;
}

int Solution::containerWithMostWater(vector<int>& input) {
	int maxArea = 0;
	int leftIndex = 0;
	int rightIndex = input.size() - 1;
	int width = 0;
	int height = 0;
	while ( leftIndex < rightIndex ) {
		width = rightIndex - leftIndex;	
#if 0
		height = MIN(input[leftIndex], input[rightIndex]);
		maxArea = MAX(maxArea, width * height);
#endif
		/* get the min of two lines */
		height = min(input[leftIndex], input[rightIndex]);
		/* update maxArea */
		maxArea = max(maxArea, width * height);
		// (height == input[leftIndex]) ? leftIndex++ : rightIndex--;
		/* move leftIndex if that is short, otherwise move rightIndex */
		if (height == input[leftIndex]) {
			leftIndex++;
		} else {
			rightIndex--;
		}
	}
	return maxArea;
}
