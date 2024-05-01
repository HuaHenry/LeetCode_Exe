# [53. 最大子数组和](https://leetcode.cn/problems/maximum-subarray/)

![image-20240501222101070](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240501222101070.png)

直接使用**前缀和**即可。获取“最大子数组和”的过程就是对于前缀和的每一项，减去这一项之前的最小前缀和，就获得了此时此刻的最大串。遍历每一个位置获得总体的最大子数组和即可。

详见代码：

```c++
class Solution {
public:
    int preSum[100005];

    int maxSubArray(vector<int>& nums) {
        for(int i=1;i<=nums.size();i++){
            preSum[i] = preSum[i-1] + nums[i-1];
        }
        //遍历前缀和序列，寻找每一个前缀和前的最小前缀和
        int ans = preSum[1] - 0;
        int min_pre = min(0,nums[0]);
        for(int i=2;i<=nums.size();i++){
            ans = max(ans,preSum[i]-min_pre);
            min_pre = min(min_pre,preSum[i]);
        }
        return ans;
    }
    
};
```

时间复杂度：$O(N)$

