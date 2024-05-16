# [240. 搜索二维矩阵 II](https://leetcode.cn/problems/search-a-2d-matrix-ii/)

![image-20240516183231666](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240516183231666.png)

![image-20240516183245403](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240516183245403.png)

![image-20240516183259022](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240516183259022.png)

根据题目要求：

- 每行的元素从左到右升序排列。
- 每列的元素从上到下升序排列。

因此满足关系如下：（思路来源于 `leetcode` 官方题解）

<img src="http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240516183421905.png" alt="image-20240516183421905" style="zoom:50%;" />

Code：

```cpp
class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 从 [0,n-1] 开始搜索，z形搜索法
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0, col = n-1;
        while(true){
            if( row<0 || row>m-1 || col<0 || col>n-1 ) return false;
            else if(matrix[row][col]==target) return true;
            else if(matrix[row][col]>target) col--;
            else row++;
        }
        return false;
    }
};
```