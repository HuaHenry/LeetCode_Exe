# [807. 保持城市天际线](https://leetcode.cn/problems/max-increase-to-keep-city-skyline/)

![image-20240714212242579](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240714212242579.png)

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/06/21/807-ex1.png)

```
输入：grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
输出：35
解释：建筑物的高度如上图中心所示。
用红色绘制从不同方向观看得到的天际线。
在不影响天际线的情况下，增加建筑物的高度：
gridNew = [ [8, 4, 8, 7],
            [7, 4, 7, 7],
            [9, 4, 8, 7],
            [3, 3, 3, 3] ]
```

**示例 2：**

```
输入：grid = [[0,0,0],[0,0,0],[0,0,0]]
输出：0
解释：增加任何建筑物的高度都会导致天际线的变化。
```

 

**提示：**

- `n == grid.length`
- `n == grid[r].length`
- `2 <= n <= 50`
- `0 <= grid[r][c] <= 100`



本题的思路很简单：如果不能破坏天际线，也就是说不能高于一行中最高的、且不能高于一列中最高的。

因此两次遍历可以解决：

- 第一次遍历记录行最高值和列最高值
- 第二次遍历记录每个元素距离 min(行最高，列最高) 的距离，家和即为答案



Code：

```cpp
class Solution {
public:
    // 记录行列的天际线高度
    int rowH[55];
    int colH[55];

    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        // 第一次遍历获取天际线高度
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>rowH[i]) rowH[i] = grid[i][j];
                if(grid[i][j]>colH[j]) colH[j] = grid[i][j];
            }
        }
        // 第二次遍历计算增长值
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans += min(rowH[i],colH[j])-grid[i][j];
            }
        }
        return ans;
    }
};
```









