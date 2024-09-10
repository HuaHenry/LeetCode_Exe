# [198. 打家劫舍](https://leetcode.cn/problems/house-robber/)

![image-20240910152420528](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240910152420528.png)

简单的dp问题：
$$
money[i] = nums[i] + \max(money[i-2],money[i-3])
$$
Code：

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> money(nums.size());     // 不要对计科人的英语和变量命名有太高的要求...

        // money[i] = muns[i] + max(money[i-2],money[i-3])
        for(int i=0;i<nums.size();i++){
            if(i-2<0) money[i] = nums[i];
            else if(i-3<0) money[i] = nums[i] + money[i-2];
            else money[i] = nums[i] + max(money[i-2],money[i-3]);
        }

        if(nums.size()==1) return money[0];
        return max(money[nums.size()-1],money[nums.size()-2]);
    }
};
```

不配作为中等题（