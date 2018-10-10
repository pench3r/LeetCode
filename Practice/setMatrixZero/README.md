#### problem

> Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
> 
> Example 1:
> 
> Input: 
> [
>   [1,1,1],
>   [1,0,1],
>   [1,1,1]
> ]
> Output: 
> [
>   [1,0,1],
>   [0,0,0],
>   [1,0,1]
> ]
> Follow up:
> 
> A straight forward solution using O(mn) space is probably a bad idea.
> A simple improvement uses O(m + n) space, but still not the best solution.
> Could you devise a constant space solution?

#### thinking:

个人的思路：首先是需要遍历`matrix`,判断是否有`0`,发现`0`后使用`set`来保存对应的`row`和`col`,最后通过遍历保存的`row`和`col`进行对应行和列的更新就可以了

优化的思路：我这里使用set保存了对应的标记状态,因此优化需要替换别的方式来进行标记状态的保存。这里借鉴别人的思路,直接使用`matrix`的`首行`和`首列`来保存对应的状态,这样就节省了多余的空间来进行操作。

别人的思路： 首先先遍历第一行是否存在`0`,如果存在设置标记`row`为`true`;然后接着遍历第一列是否存在`0`,如果存在设置标记`col`为`true`; 然后如果`row`或者`col`有为`ture`的情况,则更新`[0][0]`为0; 接着从`[1][1]`开始遍历当碰到`0`的情况则依次更新对应`首列`和`首行`的元素为`0`; 最后开始依次处理,从`首行`的`第二列`开始碰到`0`,就`更新该列`的元素为`0`,如果不为`0`,则判断`row`是否为`true`,更新`该位置`为`0`; 同样的情况处理首列并从第二行开始。 他的思路是先保存第一行和第一列的状态是否需要更新,然后借助`matrix`的`首行`和`首列`作为标记存储,如果中间的某行某列的数据为`0`只需要更新对应的`首行`和`首列`即可;最后依据`首行`和`首列`存储的标记直接更新对应的行和列。

#### 碰见的问题

- 自己实现的版本中不太熟悉set的使用方法,通过cpp reference学习使用
- 在做逻辑实现的时候一些判断需要自己想明白,并准确实现,要不然后回头debug会浪费很多时间
