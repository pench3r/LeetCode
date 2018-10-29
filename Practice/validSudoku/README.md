#### problem

> Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
> 
> 1. Each row must contain the digits 1-9 without repetition.
> 1. Each column must contain the digits 1-9 without repetition.
> 1. Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Input:
<pre>[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]</pre>
Output: true

> Note:
> 
> - A Sudoku board (partially filled) could be valid but is not necessarily solvable.
> - Only the filled cells need to be validated according to the mentioned rules.
> - The given board contain only digits 1-9 and the character '.'.
> - The given board size is always 9x9.

#### thinking:

个人思路: 通过遍历所有元素,并保存3种位置的标记行、列、9x9矩阵.主要优化使用什么方式来保存标记,由于每个位置出现的数字大小都是`0-9`,考虑使用binary的bit位来标记,使用`&`来判断每个位置对应的行、列、矩阵是否有标记位.对于矩阵需要使用`row`和`col`来计算对应的索引位置.

由于这个题目个人思路已经很偏向最优解就没有再去查找别人的思路

#### 碰见的问题

- 在转换`char`为`int`时,直接使用`int`类型转换时只能获取到对应字符的十进制,使用`char`-'0'可以获得正确的数值
- 在第一次实现时对于标记为的设置使用先右移位置,更新标记后再左移位置,这样导致有些标记位被清除,因此正确的方式应该为将1左移,通过`or`的方式更新对应位置的信息
- 本地调试没有问题,但是在提交验证时一直失败,后来更新整个提交代码,验证通过,这里需要每一步操作都需要细心避免时间的浪费
