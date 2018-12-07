#### problem

> Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
> 
> For example, given the following triangle
> 
> [
>      [2],
>     [3,4],
>    [6,5,7],
>   [4,1,8,3]
> ]
> The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
> 
> Note:
> 
> Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

#### thinking:

个人思路: 该题适合使用dp来解答,自顶向下的方式.首先找到状态,通过dp[r][c]来表示到第r行的第c个元素(r和c都是从0开始)所需要的最短路径的值.接着是状态的迁移过程,这里我们分情况来讨论针对于每行的头和尾迁移的公式为: `dp[r][0] = dp[r-1][0] + triangle[r][0]`、`dp[r][r](这里代表每行的尾部元素)=dp[r-1][r-1] + triangle[r][r]`;还有介于每行的头和尾中间的元素: `dp[r][c] = min(dp[r-1][c-1], dp[r-1][c]) + triangle[r][c]`这里需要考虑清楚边界问题以及如果确定与其相邻的元素;在实现中外层循环从第一层开始,并开始处理每行的头和尾元素,内层循环开始更新每个位置的值,到最外层的时候开始判断保存我们需要的结果

别人的思路: 可以从底往上进行计算,这样不需要处理特殊情况,对于每个位置的元素都可以使用同一个迁移公式来处理: `dp[r][c] = min(dp[r+1][c], dp[r+1][c+1]) + triangle[r][c]`

#### 碰见的问题

- 有些特殊情况没有考虑到,当输入为一行时没有进行处理
- 第一次实现时由于当时在外循环中单独的处理每行的头和尾,但是在输出最后结果时并没有针对与头和尾参与比较,导致的bug存在

#### 总结

- 针对于dp的题目,首先需要找到状态和状态迁移的情况,接着再去考虑具体的实现
- 花费时间考虑的细节包括: 行数和列数的实现、行和列的边界、对于每个节点更新值的存储、以及最后结果如何去提取
- 对于特殊情况的考虑,如每行头和尾元素的处理、只有一行的处理、针对与中间节点的相邻节点确定
