class Solution
{
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        // 从 [0,n-1] 开始搜索，z形搜索法
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0, col = n - 1;
        while (true)
        {
            if (row < 0 || row > m - 1 || col < 0 || col > n - 1)
                return false;
            else if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                col--;
            else
                row++;
        }
        return false;
    }
};