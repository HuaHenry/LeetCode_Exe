class Solution
{
public:
    void setZeroes(vector<vector<int> > &matrix)
    {
        // 原地算法
        // 存储行列0值
        unordered_set<int> rows;
        unordered_set<int> cols;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    cout << "1" << endl;
                    if (rows.count(i) == 0)
                    {
                        rows.insert(i);
                        // cout<<"2"<<endl;
                    }
                    if (cols.count(j) == 0)
                        cols.insert(j);
                }
            }
        }
        // 开始置零
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (rows.count(i) != 0 || cols.count(j) != 0)
                    matrix[i][j] = 0;
            }
        }
    }
};