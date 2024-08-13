class Solution
{
public:
    int len;
    vector<vector<int> > ans;

    void generate_list(vector<int> vis, vector<int> &nums, vector<int> ans_now, int len_now)
    {
        if (len_now == len)
            ans.push_back(ans_now);
        else
        {
            len_now++;
            for (int i = 0; i < len; i++)
            {
                if (vis[i] == 0)
                {
                    vis[i] = 1;
                    ans_now.push_back(nums[i]);
                    generate_list(vis, nums, ans_now, len_now);
                    ans_now.pop_back();
                    vis[i] = 0;
                }
            }
        }
    }

    vector<vector<int> > permute(vector<int> &nums)
    {
        len = nums.size();
        vector<int> vis(len);
        vector<int> ans_now;
        generate_list(vis, nums, ans_now, 0);
        return ans;
    }
};