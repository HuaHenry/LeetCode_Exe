class Solution
{
public:
    vector<vector<int> > generate(int numRows)
    {
        vector<vector<int> > ans;
        vector<int> first = {1};
        ans.push_back(first);
        for (int i = 1; i < numRows; i++)
        {
            // 每行赋值
            vector<int> tmp;
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0)
                    tmp.push_back(ans[i - 1][j]);
                else if (j == i)
                    tmp.push_back(ans[i - 1][j - 1]);
                else
                    tmp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};