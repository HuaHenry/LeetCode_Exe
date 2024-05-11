# [48. 旋转图像](https://leetcode.cn/problems/rotate-image/)

![image-20240511173452454](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240511173452454.png)

![image-20240511173508572](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240511173508572.png)



该题的难点在于“**原地旋转**”，不使用额外的空间。因此对于每一个元素 `(x,y)` 需要替换坐标 `(y,n-x-1)` 位置的元素。

由于“覆盖”，需要使用临时变量存储被覆盖值，且一次移动4次以达到闭合的旋转（不然临时变量也会被覆盖）。

具体详见代码。

Code：

```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //根据数学原理可获得，(x,y) -> (y,(len-1)-x)
        int n = matrix.size();
        for(int i=0;i<n/2;i++){
            for(int j=0;j<(n+1)/2;j++){
                //内部实现4次旋转
                int row = i, col = j;
                int tmp = matrix[i][j];
                for(int cnt=0;cnt<4;cnt++){
                    int now = matrix[col][(n-1)-row];
                    matrix[col][(n-1)-row] = tmp;
                    tmp = now;
                    now = col;
                    col = (n-1-row); row = now;
                }
            }
        }
    }
};
```

