class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        int m = board.size(), n = board[0].size();
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(board[row][col]=='.'){
                    continue;
                }
                else if(board[row][col]=='*'){
                    // 连通位置
                    if(col+1!=n && board[row][col+1]!='.')
                        board[row][col+1] = '*';
                    else if(row+1!=m && board[row+1][col]!='.')
                        board[row+1][col] = '*';
                }
                else{
                    if(col+1!=n && board[row][col+1]!='.')
                        board[row][col+1] = '*';
                    else if(row+1!=m && board[row+1][col]!='.')
                        board[row+1][col] = '*';
                    res ++;
                }
            }
        }
        return res;
    }
};