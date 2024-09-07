# [994. 腐烂的橘子](https://leetcode.cn/problems/rotting-oranges/)

![image-20240907162408033](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240907162408033.png)

![image-20240907162430492](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240907162430492.png)

本题正统的解法应当是BFS（广度优先搜索），本人使用的是深度优先搜索，在空间复杂度上会略高，不过也可以解决问题。思路见代码。

Code：

```cpp
class Solution {
public:
    vector<vector<int>> times;
    vector<vector<int>> grid_gb;

    void check(int x, int y, int time_now){
        if(grid_gb[x][y]==1){
                grid_gb[x][y]=2;
                times[x][y]=time_now;
                dfs(x,y,time_now+1);
            }
            else if(grid_gb[x][y]==2 && times[x][y]>time_now){
                times[x][y]=time_now;
                dfs(x,y,time_now+1);
            }
    }

    void dfs(int x, int y, int time_now){
        if(x!=0){
            check(x-1,y,time_now);
        }
        if(x!=grid_gb.size()-1){
            check(x+1,y,time_now);
        }
        if(y!=0){
            check(x,y-1,time_now);
        }
        if(y!=grid_gb[0].size()-1){
            check(x,y+1,time_now);
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        grid_gb = grid;
        for(int i=0;i<row;i++){
            vector<int> tmp;
            for(int j=0;j<col;j++){
                tmp.push_back(-1);
            }
            times.push_back(tmp);
        }
        //腐蚀
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2) dfs(i,j,1);
            }
        }
        //检查
        int res = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid_gb[i][j]==1) return -1; 
                else{
                    res = max(res,times[i][j]);
                }
            }
        }
        return res;
    }
};
```

