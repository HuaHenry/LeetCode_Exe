class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        // 使用双向队列存储数组
        deque<int> dq;
        int n = arr.size();
        for (int i = 0; i < arr.size(); i++)
        {
            dq.push_back(arr[i]);
        }
        // 使用哈希表存储个数映射关系
        unordered_map<int, int> ump;
        while (true)
        {
            int x1 = dq.front();
            dq.pop_front();
            int x2 = dq.front();
            dq.pop_front();
            int maxn = max(x1, x2), minn = min(x1, x2);
            ump[maxn]++;
            if (ump[maxn] == k || ump[maxn] > n)
                return maxn;
            dq.push_front(maxn);
            dq.push_back(minn);
        }
    }
};