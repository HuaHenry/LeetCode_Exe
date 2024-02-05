# [1696. 跳跃游戏 VI](https://leetcode.cn/problems/jump-game-vi/)

![image-20240205162127753](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240205162127753.png)

![image-20240205162136141](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240205162136141.png)



主要思路为**优先队列 + dp**

dp思路为：第 $x$ 步的最高等分 = 前 $k$ 步最高得分 + $nums[x]$，可以构建动态规划的路径。

优先队列用于存储前 k 步的得分，并使用 while 循环清除超过 k 步的部分



Code：

```c++
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        q.emplace(nums[0], 0);
        int ans = nums[0];
        
        for (int i = 1; i < n; ++i) {
            while (i - q.top().second > k) {
                q.pop();
            }
            
            ans = q.top().first + nums[i];
            q.emplace(ans, i);
        }
        
        return ans;
    }
};
```

