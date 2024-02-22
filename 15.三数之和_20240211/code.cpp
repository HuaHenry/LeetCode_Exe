class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &nums)
    {
        // 三个元素 i,j,k，遍历i，双指针枚举j和k
        int n = nums.size();
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = n - 1;
            if (nums[i] > 0)
                return ans;
            while (left < right)
            {
                if (nums[left] + nums[right] + nums[i] > 0)
                    right--;
                else if (nums[left] + nums[right] + nums[i] < 0)
                    left++;
                else
                {
                    cout << nums[i] << ' ' << nums[left] << ' ' << nums[right] << endl;
                    //==0
                    // 判断下一位置是否存在重复
                    if (left != right - 1 && (nums[left + 1] == nums[left]))
                    {
                        left++;
                        continue;
                    }
                    else if (left != right - 1 && (nums[right - 1] == nums[right]))
                    {
                        right--;
                        continue;
                    }
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    ans.push_back(tmp);
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};