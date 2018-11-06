#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
/*	int numberCount;
	cin>>numberCount;
	vector<int> inputArray;
	int index=0;
	int temp;
	while(index < numberCount) {
		cin>>temp;
		inputArray.push_back(temp);
		index++;
	}
	sort(inputArray.begin(), inputArray.end());
	// inputArray.resize(distance(inputArray.begin(), unique(inputArray.begin(), inputArray.end())));
	inputArray.erase(unique(inputArray.begin(), inputArray.end()), inputArray.end());
	for (int index=0; index < inputArray.size(); ++index) {
		cout << inputArray[index] << endl;
	}
*/
	int numberCount, index;
	/* 从开始接受数组的大小开始一组测试, 这样程序可以一直运行接受数据 */
	while (cin >> numberCount) {
		/* 使用该数组保存以输入为key，value为1来标记出现过的key */
		/* 这种方式只能确保输入数据中没有超过1001的值 */
		int inputArray[1001] = {0};
		/* 开始循环遍历接收指定的元素个数 */
		while (numberCount--) {
			cin >> index;
			/* 将接收的值作为key，将其对应的value设置为1 */
			inputArray[index]=1;	
		}	
		for (int i=0; i<1001; ++i) {
			/* 从头开始遍历数组,巧妙的利用了index的线性关系再配合value的标记 */
			if (inputArray[i]) {
				cout << i << endl;
			}
		}
	}
	return 0;
}
