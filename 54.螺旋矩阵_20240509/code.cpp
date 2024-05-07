class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix)
    {
        // 定义上下左右边界
        int l = 0, r = matrix[0].size() - 1, u = 0, d = matrix.size() - 1;
        if (matrix.empty())
            return vector<int>{};
        vector<int> ans;
        while (true)
        {
            // 向右
            for (int i = l; i <= r; i++)
            {
                ans.push_back(matrix[u][i]);
            }
            if (++u > d)
                break;
            // 向下
            for (int i = u; i <= d; i++)
            {
                ans.push_back(matrix[i][r]);
            }
            if (--r < l)
                break;
            // 向左
            for (int i = r; i >= l; i--)
            {
                ans.push_back(matrix[d][i]);
            }
            if (--d < u)
                break;
            // 向上
            for (int i = d; i >= u; i--)
            {
                ans.push_back(matrix[i][l]);
            }
            if (++l > r)
                break;
        }
        return ans;
    }
};