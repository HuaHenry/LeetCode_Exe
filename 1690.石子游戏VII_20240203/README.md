# [1690. 石子游戏 VII](https://leetcode.cn/problems/stone-game-vii/)



![image-20240203154226645](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240203154226645.png)

![image-20240203154256837](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240203154256837.png)



使用 **dp** 思想：（直接参考官方题解的思路更为清晰）

<img src="http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240203154353371.png" alt="image-20240203154353371" style="zoom:50%;" />



Code：

```c++
class Solution {
public:

    int stoneGameVII(vector<int>& stones) {
        //dp求解
        const int N = stones.size();
        //前缀和数组
        int sum[10000]={0};
        for(int i=0;i<N;i++){
            sum[i+1] = sum[i]+stones[i];
        }
        //dp数组
        int dp[1000][1000]={0};
        for (int i = N - 2; i >= 0; i--) {
            for (int j = i + 1; j < N; j++) {
                dp[i][j] = max(sum[j + 1] - sum[i + 1] - dp[i + 1][j], sum[j] - sum[i] - dp[i][j - 1]);
            }
        }
        return dp[0][N-1];
    }
};
```

