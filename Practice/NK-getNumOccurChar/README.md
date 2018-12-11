#### 题目描述 ####

接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写

#### 思路 ####

个人思路: 使用`cin`分别获取这`2`个输入,由于只会出现字母和数字以及空格,使用固定`128`的数组来保存出现的所有字符的次数,这里需要注意转换字符的大小写,通过`+-32`来进行转换,最后直接输出数组以想收集的字符为`key`对应的值即可

#### 知识点 ####

- 通过`while(cin>>num1>>num2)`可以每次都获取这两个输入
- 主要利用每个字符对应的`ascii`的范围,通过数组来保存每个字符出现的次数,`key`为该字符的`ascii`值