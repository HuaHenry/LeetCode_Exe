class Solution
{
public:
    int climbStairs(int n)
    {
        // dp思路：dp[i]表示到达第k阶时的方法个数
        int dp[n + 1];
        memset(dp, 0, 4 * (n + 1));
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i > 0)
                dp[i] += dp[i - 1];
            if (i > 1)
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};