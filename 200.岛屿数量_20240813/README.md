# [200. 岛屿数量](https://leetcode.cn/problems/number-of-islands/)

![image-20240813124025730](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240813124025730.png)

![image-20240813124048887](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240813124048887.png)

遇到过较为简单的图论题（不知道为啥是medium难度），直接dfs遍历四周块即可。注意可以直接修改原数组，以实现记忆化功能。

Code：

```cpp
class Solution {
public:
    int ans = 0;
    int row, col;
    vector<vector<char>> maps;

    void dfs(int x, int y){
        if(x-1>=0 && maps[x-1][y]=='1'){
            maps[x-1][y] = '2';
            dfs(x-1,y);
        }
        if(y-1>=0 && maps[x][y-1]=='1'){
            maps[x][y-1] = '2';
            dfs(x,y-1);
        }
        if(x+1<row && maps[x+1][y]=='1'){
            maps[x+1][y] = '2';
            dfs(x+1,y);
        }
        if(y+1<col && maps[x][y+1]=='1'){
            maps[x][y+1] = '2';
            dfs(x,y+1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        row = grid.size(), col = grid[0].size();
        maps = grid;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(maps[i][j]=='1'){
                    ans++;
                    maps[i][j] = '2';
                    dfs(i,j);
                }
            }
        }
        return ans;
    }
};
```

