class Solution
{
public:
    // 记录行列的天际线高度
    int rowH[55];
    int colH[55];

    int maxIncreaseKeepingSkyline(vector<vector<int> > &grid)
    {
        // 第一次遍历获取天际线高度
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] > rowH[i])
                    rowH[i] = grid[i][j];
                if (grid[i][j] > colH[j])
                    colH[j] = grid[i][j];
            }
        }
        // 第二次遍历计算增长值
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                ans += min(rowH[i], colH[j]) - grid[i][j];
            }
        }
        return ans;
    }
};