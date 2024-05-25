class Solution
{
public:
    vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference)
    {
        // 暴力出奇迹
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (abs(i - j) >= indexDifference && abs(nums[i] - nums[j]) >= valueDifference)
                    return vector<int>{i, j};
            }
        }
        return vector<int>{-1, -1};
    }
};