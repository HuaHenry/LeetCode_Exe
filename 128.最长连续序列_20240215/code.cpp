class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // 使用集合去重
        unordered_set<int> st;
        for (auto i : nums)
        {
            st.insert(i);
        }
        int ans = 0;
        for (auto it : nums)
        {
            if (st.count(it - 1))
                continue;
            int tmp = it;
            while (st.count(++tmp))
                ;
            ans = max(ans, tmp - it);
        }
        return ans;
    }
};