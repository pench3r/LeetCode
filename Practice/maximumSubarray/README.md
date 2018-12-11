#### problem:

> Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
> 
> Example:
> 
> Input: [-2,1,-3,4,-1,2,1,-5,4],
> Output: 6
> Explanation: [4,-1,2,1] has the largest sum = 6.
> Follow up:
> 
> If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

#### thinking:

个人思路: 采用一次遍历的方式,依次累加保存遍历中的最大和,当和小于0时,重置sum的值为0继续遍历.主要通过计算和来确定最长的字串和,由于当和小于0时对于后面的串来说没有意义.

#### 总结:

- 通过分析题目中指出的线性连续的子串,转化为遍历和的过程
