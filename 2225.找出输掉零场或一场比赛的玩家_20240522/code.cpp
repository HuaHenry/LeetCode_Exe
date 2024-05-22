class Solution
{
public:
    vector<vector<int> > findWinners(vector<vector<int> > &matches)
    {
        int win[100005] = {0};
        int lose[100005] = {0};
        // 遍历录入数据
        for (int i = 0; i < matches.size(); i++)
        {
            win[matches[i][0]]++;
            lose[matches[i][1]]++;
        }
        // 计算结果
        vector<int> ans1;
        vector<int> ans2;
        for (int i = 0; i < 100005; i++)
        {
            if (win[i] != 0 && lose[i] == 0)
            {
                ans1.push_back(i);
            }
            if (lose[i] == 1)
            {
                ans2.push_back(i);
            }
        }
        vector<vector<int> > ans;
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};