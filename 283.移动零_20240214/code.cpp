class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int tmp = -1;
        for (auto i : nums)
        {
            if (i != 0)
                nums[++tmp] = i;
        }
        // 末尾置零
        tmp++;
        for (tmp; tmp < nums.size(); tmp++)
        {
            nums[tmp] = 0;
        }
    }
};