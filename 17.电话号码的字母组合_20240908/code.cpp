class Solution
{
public:
    vector<string> ans;

    void dfs(string now_ans, string digits, int index, string info[10])
    {
        if (index >= digits.size())
        {
            ans.push_back(now_ans);
            return;
        }
        int find_index = digits[index] - '0';
        for (int i = 0; i < info[find_index].size(); i++)
        {
            now_ans.push_back(info[find_index][i]);
            dfs(now_ans, digits, index + 1, info);
            now_ans.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        string info[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        ans.clear();
        if (digits.empty())
            return ans;
        dfs("", digits, 0, info);
        return ans;
    }
};