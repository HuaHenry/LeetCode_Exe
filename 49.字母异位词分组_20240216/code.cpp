class Solution
{
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs)
    {
        // 思路：按照从小到大的字母排序作为哈希key
        unordered_map<string, vector<string> > mid;
        vector<vector<string> > ans;
        for (int i = 0; i < strs.size(); i++)
        {
            string tmp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mid[strs[i]].push_back(tmp);
        }
        for (auto &i : mid)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};