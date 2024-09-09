class Solution
{
public:
    vector<string> ans;
    unordered_set<string> ans_set;

    void dfs(string ans_now, int n, int index)
    {
        if (index > n)
        {
            if (ans_set.count(ans_now))
                return;
            ans.push_back(ans_now);
            ans_set.insert(ans_now);
            return;
        }
        // 首先放在最前面
        dfs("()" + ans_now, n, index + 1);
        // 找左括号的右侧插入
        for (int i = 0; i < ans_now.size(); i++)
        {
            if (ans_now[i] == '(')
            {
                string leftSide = ans_now.substr(0, i + 1);
                string rightSide = ans_now.substr(i + 1);
                string tmp = leftSide + "()" + rightSide;
                dfs(tmp, n, index + 1);
            }
        }
    }

    vector<string> generateParenthesis(int n)
    {
        dfs("", n - 1, 0);
        return ans;
    }
};