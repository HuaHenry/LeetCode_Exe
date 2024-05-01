class Solution
{
public:
    int preSum[100005];

    int maxSubArray(vector<int> &nums)
    {
        for (int i = 1; i <= nums.size(); i++)
        {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        // 遍历前缀和序列，寻找每一个前缀和前的最小前缀和
        int ans = preSum[1] - 0;
        int min_pre = min(0, nums[0]);
        for (int i = 2; i <= nums.size(); i++)
        {
            ans = max(ans, preSum[i] - min_pre);
            min_pre = min(min_pre, preSum[i]);
        }
        return ans;
    }
};