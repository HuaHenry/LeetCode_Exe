# [79. 单词搜索](https://leetcode.cn/problems/word-search/)

![image-20240910144517910](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240910144517910.png)

![image-20240910144534549](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240910144534549.png)

![image-20240910144551585](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240910144551585.png)

简单的回溯问题，dfs + 剪枝 + 回溯即可解决问题。

Code：

```cpp
class Solution {
public:
    vector<vector<bool>> used;

    bool dfs(vector<vector<char>>& board, string word, int index, int x, int y){
        // cout<<x<<' '<<y<<endl;
        if(word[index]!=board[x][y]) return false;
        if(index==word.size()-1) return true;
        used[x][y] = true;
        if(x>0 && !used[x-1][y] && word[index+1]==board[x-1][y] && dfs(board, word, index+1, x-1, y)) return true;
        if(x<board.size()-1 && !used[x+1][y] && word[index+1]==board[x+1][y] && dfs(board, word, index+1, x+1, y)) return true;
        if(y>0 && !used[x][y-1] && word[index+1]==board[x][y-1] && dfs(board, word, index+1, x, y-1)) return true;
        if(y<board[0].size()-1 && !used[x][y+1] && word[index+1]==board[x][y+1] && dfs(board, word, index+1, x, y+1)) return true;
        used[x][y] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for(int i=0;i<row;i++){
            vector<bool> tmp;
            for(int j=0;j<col;j++){
                tmp.push_back(false);
            }
            used.push_back(tmp);
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(dfs(board,word,0,i,j)) return true;
            }
        }
        return false;
    }
};
```

