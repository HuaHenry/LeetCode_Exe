class Solution
{
public:
    vector<vector<int> > res;

    void ListAns(vector<int> &nums, vector<bool> use, vector<int> tmp, int start)
    {
        res.push_back(tmp);
        for (int i = start; i < nums.size(); i++)
        {
            if (!use[i])
            {
                use[i] = true;
                tmp.push_back(nums[i]);
                ListAns(nums, use, tmp, start + 1);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int> > subsets(vector<int> &nums)
    {
        vector<bool> use(nums.size(), false);
        vector<int> tmp;
        ListAns(nums, use, tmp, 0);
        return res;
    }
};