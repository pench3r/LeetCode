#include <iostream>
#include <string.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

static int cutSteelBar(int steelBarPriceTable[], int neededToCut);

int main(int argc, char *argv[]) {
	int steelBarPriceTable[] = {1,5,8,9,10,17,17,20,24,30};
	cout << "max profit: " << cutSteelBar(steelBarPriceTable, 9) << endl;
	return 0;
}

static int cutSteelBar(int steelBarPriceTable[], int neededToCut) {
	/* 初始化保存收益的数组 */
	int *profit = new int[neededToCut + 1];
	unordered_map<int,int> plan;
	memset(profit, 0, sizeof(int)*(neededToCut+1));
	/* 外层循环,依次计算1,2,...,n长度的最优收益 */
	for (int totalLen=1; totalLen <= neededToCut; ++totalLen) {
		int maxProfit = -1;
		/* 内层循环,左边为1,...totalLen长度时,寻找最大收益 */
		for (int leftLen=1; leftLen <= totalLen; ++leftLen) {
			maxProfit = max(maxProfit, steelBarPriceTable[leftLen-1] + profit[totalLen - leftLen]);	
			if(plan.find(maxProfit) == plan.end() && maxProfit == (max(maxProfit, steelBarPriceTable[leftLen-1] + profit[totalLen - leftLen]))) {
				/* 保存最优收益与左边长度的映射关系 */
				plan[maxProfit] = leftLen;
			}
		}
		profit[totalLen] = maxProfit;
	}
	int maxP = profit[neededToCut];
	while (maxP != 0) {
		/* 输出对应的收益保存的左边长度 */
		cout << plan[maxP] << endl;
		/* 计算剩余的收益值,进行下次遍历 */
		maxP = maxP - steelBarPriceTable[plan[maxP] - 1];
	}
	return profit[neededToCut];
}
