class Solution
{
public:
    vector<vector<int> > merge(vector<vector<int> > &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int> > ans;
        int start = -1;
        int end = -1;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (start != -1)
                intervals[i][0] = start;
            if (end != -1)
            {
                intervals[i][1] = max(intervals[i][1], end);
            }

            if (i == intervals.size() - 1)
            {
                ans.push_back(intervals[i]);
                continue;
            }
            // 非最后一个元素
            // 开始排查后续元素
            if (intervals[i + 1][0] <= intervals[i][1])
            {
                // 可以继续合并，需要替换 end start
                end = intervals[i][1];
                start = intervals[i][0];
            }
            else
            {
                // 不能继续合并
                ans.push_back(intervals[i]);
                end = -1;
                start = -1;
            }
        }
        return ans;
    }
};