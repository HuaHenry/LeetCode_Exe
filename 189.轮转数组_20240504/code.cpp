class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(nums[(i - k + 10 * n) % n]);
        }
        nums = ans;
    }
};