#### problem: ####

> Given an array of integers, return indices of the two numbers such that they add up to a specific target.
> 
> You may assume that each input would have exactly one solution, and you may not use the same element twice.
> 
> Example:
> 
> Given nums = [2, 7, 11, 15], target = 9,
> 
> Because nums[0] + nums[1] = 2 + 7 = 9,
> return [0, 1].

#### thinking: ####

题目本质是配对找到`a + b = target`,并且输入的元素不存在重复。这样必定需要进行遍历来记录所有元素的信息，在第一次实现时直接嵌套2层for循环进行两次遍历，使用的数据结构为`vector`, 时间复杂度为`n的平方`. 

优化:将每个元素的索引与`target-元素的值`通过`hash表`建立`kv`的关系，使用`hash表`的优点为key唯一，搜索速度快。使用`c++11`中的`unordered_map`进行kv存储，我这里先进行了一次遍历初始化`hash表`,接着又遍历了一次`vector`,优化后效果显著。

PS：最后查看discuss中发现，直接通过一次遍历就可以达到目标，在遍历中先查看元素对应的`target-element`是否存在于hash表中，存在直接返回结果，不存在则插入到hash表中。由于这里有唯一解，假如结果为[i,j],当遍历到j时，i索引的相关信息肯定已经存入hash表中，这样实现更优雅理论上该解法速度更快。

#### soultion: ####

	class Solution {
	public:
	    vector<int> twoSum(vector<int>& nums, int target) {
	        unordered_map<int, int> indices = {};
	        for (int i=0; i < nums.size(); ++i) {
	            indices[target - nums[i]] = i;
	        }
	        for(int i=0; i < nums.size(); ++i) {
	            if (indices.count(nums[i]) && indices[nums[i]] != i) {
	                return {i, indices[nums[i]]};
	            } else {
	                indices.erase(nums[i]);
	            }
	        }
	        return {};
	    }
	};

#### 中间碰到的问题： ####

- 对于unordered_map和vector的使用不太了解，通过cppreference查询获取用法和语法
- 有些特殊情况在一开始没有考虑清楚，例如输入为[3, 2, 4]就会返回[0,0],添加特殊情况的处理，正常返回结果
