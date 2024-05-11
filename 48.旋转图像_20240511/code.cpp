class Solution
{
public:
    void rotate(vector<vector<int> > &matrix)
    {
        // 根据数学原理可获得，(x,y) -> (y,(len-1)-x)
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < (n + 1) / 2; j++)
            {
                // 内部实现4次旋转
                int row = i, col = j;
                int tmp = matrix[i][j];
                for (int cnt = 0; cnt < 4; cnt++)
                {
                    int now = matrix[col][(n - 1) - row];
                    matrix[col][(n - 1) - row] = tmp;
                    tmp = now;
                    now = col;
                    col = (n - 1 - row);
                    row = now;
                }
            }
        }
    }
};