#### 题目描述 ####

输入多行，先输入随机整数的个数，再输入相应个数的整数,返回多行排序和去重处理后的结果

input:

> 11
> 10
> 20
> 40
> 32
> 67
> 40
> 20
> 89
> 300
> 400
> 15

output:

> 10
> 15
> 20
> 32
> 40
> 67
> 89
> 300
> 400

#### 思路 ####

个人思路: 通过`cin`获取相关的输入,由于输入的随机数是在`1-1000`范围中,因此使用`1001`的数组来保存对应数值出现的标记(通过这个标记可以达到去重的效果),在输出的时候使用`for`的`index`线性关系来达到排序的作用,然后遍历整个数组输出被标记的数的`key`,就是我们需要的结果

#### 知识点 ####

- 通过数组标记来达到去重的效果
- 通过index的线性关系来遍历数组达到排序的作用
