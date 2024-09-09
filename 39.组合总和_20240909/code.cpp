class Solution
{
public:
    vector<vector<int> > ans;

    void findAns(vector<int> &candidates, vector<int> listNow, int index, int ans_now, int target)
    {
        if (ans_now > target)
            return;
        if (ans_now == target)
        {
            ans.push_back(listNow);
            return;
        }
        // 开始遍历选择（包括自己）
        for (int i = index; i < candidates.size(); i++)
        {
            if (ans_now + candidates[i] > target)
                continue;
            listNow.push_back(candidates[i]);
            findAns(candidates, listNow, i, ans_now + candidates[i], target);
            listNow.pop_back();
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
        vector<int> tmp;
        findAns(candidates, tmp, 0, 0, target);
        return ans;
    }
};