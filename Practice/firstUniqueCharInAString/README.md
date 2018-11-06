#### problem

> Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
> 
> Examples:
> 
> s = "leetcode"
> return 0.
> 
> s = "loveleetcode",
> return 2.
> Note: You may assume the string contain only lowercase letters.

#### thinking:

个人思路: 一开始看到这个题目没有很清楚的梳理出相关的逻辑点,后来使用思路为判断当前字符是否在后面的子字符串中出现,这个缺少了一环并没有判断该字符之前的字串中是否存在.

整理思路: 分析题干可知,第一个非重复的字符,由于是第一个所以要获取到相关字符的索引位置,非重复这里可以利用前子字符串的遍历和后子字符串的遍历、统计字符串中所有字符出现的次数,最后判断那个是否只出现过一次

实现思路: 这里可以使用array和map来保存每个字符出现的次数,但是array效率更高;在获取最后结果时,由于array本身的排序并不能确定第一次出现的字符位置,这里还是借用string[index]来依次判断第一次出现.

#### 碰见的问题

- 自己第一次做这道题没有很好的梳理思路,想到使用vector来保存出现的唯一字符,但是没有保存第一出现的这个位置
- 在提交leetcode上map实现的时间为84ms,使用array后时间为28ms.
