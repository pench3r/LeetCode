/* 还有一种方式使用C++内置的string比较操作符默认就是字典比较 */
/* 接着配合排序方法排序就可以,冒泡、快排、归并 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int charNum;
	while (cin >> charNum) {
		string inputStr;
		vector<string> strVec;
		while (charNum--) {
			cin >> inputStr;
			strVec.push_back(inputStr);
		}
		/* 使用sort进行排序 */
		sort(strVec.begin(), strVec.end());	
		/* 迭代器可以用来进行去重 */
		/* vit = upper_bound(,,value) 
			 vect.insert(vit, value)

			 vit = find(,,value)
			 vect.erase(vit)
			 插入和删除都会保持原来的顺序不会乱
		*/
		vector<string>::iterator vit;	
		for (vit = strVec.begin(); vit != strVec.end(); ++vit) {
			cout << *vit << endl;	
		}
	}
	return 0;
}
