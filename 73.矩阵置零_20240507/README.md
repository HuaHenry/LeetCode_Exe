# [73. 矩阵置零](https://leetcode.cn/problems/set-matrix-zeroes/)

![image-20240507204612592](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240507204612592.png)

![image-20240507204630247](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240507204630247.png)



本人考虑的方法是使用额外的哈希表存储具有0的行列值，具体使用`unordered_set`。

进阶中的方法都是极致的时间换空间（屎山），没有任何参考价值。。

Code：

```c++
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //原地算法
        //存储行列0值
        unordered_set<int> rows;
        unordered_set<int> cols;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    cout<<"1"<<endl;
                    if(rows.count(i)==0) rows.insert(i);
                    if(cols.count(j)==0) cols.insert(j);
                }
            }
        }
        //开始置零
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(rows.count(i)!=0 || cols.count(j)!=0) matrix[i][j]=0;
            }
        }
    }
};
```

