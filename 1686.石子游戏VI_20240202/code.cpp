class Solution
{
public:
    int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues)
    {
        // 先对双方认定的价值相加并进行排序，得到价值和的降序排序
        vector<pair<int, int> > valuesSort;
        for (int i = 0; i < aliceValues.size(); i++)
        {
            valuesSort.push_back(pair<int, int>{aliceValues[i] + bobValues[i], i});
        }
        // 使用反向迭代器降序排序
        sort(valuesSort.rbegin(), valuesSort.rend());
        // 开始计算双方得分
        int alice = 0, bob = 0;
        for (int i = 0; i < aliceValues.size(); i++)
        {
            if (i % 2)
            {
                // bob
                bob += bobValues[valuesSort[i].second];
            }
            else
            {
                // alice
                alice += aliceValues[valuesSort[i].second];
            }
        }
        return (bob == alice ? 0 : (bob > alice ? -1 : 1));
    }
};