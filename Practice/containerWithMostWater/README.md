#### problem: ####

> Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
> 
> Note: You may not slant the container and n is at least 2.


#### thinking: ####

分析题目最普通的思路：双循环遍历，计算每2条线之间的容量。时间复杂度为O(n平方);

优化思路：对于需要遍历的情况，可以尝试使用双指针的方式，从2头开始遍历这样的遍历只需要做一次就可以，而不需要内嵌循环再遍历一次，该算法的时间复杂度被优化为O(n)。

#### 中间碰到的问题： ####

- 设置rightIndex的时候需要减1因为是表示索引，而`size()`返回的是个数
- 初始化vector的时候采用的方式是c++11新增的特性，所以编译的时候要指定std
- 稍微细节的一点地方三元运算符比if else的处理更快一些
