class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<pair<int, int> > q;
        q.emplace(nums[0], 0);
        int ans = nums[0];

        for (int i = 1; i < n; ++i)
        {
            while (i - q.top().second > k)
            {
                q.pop();
            }

            ans = q.top().first + nums[i];
            q.emplace(ans, i);
        }

        return ans;
    }
};