# [70. 爬楼梯](https://leetcode.cn/problems/climbing-stairs/)

![image-20240908171850108](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240908171850108.png)

经典的动态规划问题，可以假设 $dp[i]=dp[i-1]+dp[i-2]$，表示到达第 $i$ 阶共有的方法个数。遍历一次即可实现动态规划。

Code：

```cpp
class Solution {
public:
    int climbStairs(int n) {
        //dp思路：dp[i]表示到达第k阶时的方法个数
        int dp[n+1];
        memset(dp,0,4*(n+1));
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            if(i>0) dp[i]+=dp[i-1];
            if(i>1) dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};
```

题解没有使用数组存储，确实更为方便：

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q; 
            q = r; 
            r = p + q;
        }
        return r;
    }
};
```

