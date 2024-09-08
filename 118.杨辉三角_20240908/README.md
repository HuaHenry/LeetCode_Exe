# [118. 杨辉三角](https://leetcode.cn/problems/pascals-triangle/)

![image-20240908173522767](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240908173522767.png)

![image-20240908173531346](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240908173531346.png)

本题可以直接使用数组存储的方式实现：
$$
dp[i][j] = dp[i-1][j-1]+dp[i-1][j]
$$
需要对左右两个断点特判即可。

Code：

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> first = {1};
        ans.push_back(first);
        for(int i=1;i<numRows;i++){
            //每行赋值
            vector<int> tmp;
            for(int j=0;j<i+1;j++){
                if(j==0) tmp.push_back(ans[i-1][j]);
                else if(j==i) tmp.push_back(ans[i-1][j-1]);
                else tmp.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
```

