class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        // 使用数组映射的方法，遍历查看 [1,N]
        int n = nums.size();
        // 首先遍历保证数组内元素都是正数
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 1 || nums[i] > n)
            {
                nums[i] = n + 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (abs(nums[i]) >= 1 && abs(nums[i]) <= n)
            {
                nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 0)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};