class Solution
{
public:
    int ans = 0;
    int row, col;
    vector<vector<char> > maps;

    void dfs(int x, int y)
    {
        if (x - 1 >= 0 && maps[x - 1][y] == '1')
        {
            maps[x - 1][y] = '2';
            dfs(x - 1, y);
        }
        if (y - 1 >= 0 && maps[x][y - 1] == '1')
        {
            maps[x][y - 1] = '2';
            dfs(x, y - 1);
        }
        if (x + 1 < row && maps[x + 1][y] == '1')
        {
            maps[x + 1][y] = '2';
            dfs(x + 1, y);
        }
        if (y + 1 < col && maps[x][y + 1] == '1')
        {
            maps[x][y + 1] = '2';
            dfs(x, y + 1);
        }
    }

    int numIslands(vector<vector<char> > &grid)
    {
        row = grid.size(), col = grid[0].size();
        maps = grid;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (maps[i][j] == '1')
                {
                    ans++;
                    maps[i][j] = '2';
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};