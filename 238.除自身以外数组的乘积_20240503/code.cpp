class Solution
{
public:
    int pre[100005] = {-1};
    int aft[100005] = {-1};

    vector<int> productExceptSelf(vector<int> &nums)
    {
        // 首先求前缀积
        vector<int> ans;
        int n = nums.size();
        pre[0] = 1;
        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] * nums[i - 1];
        }
        // 接着求后缀积
        aft[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            aft[i] = aft[i + 1] * nums[i + 1];
        }
        // 求最终结果
        for (int i = 0; i < n; i++)
        {
            ans.push_back(pre[i] * aft[i]);
        }
        return ans;
    }
};