# [128. 最长连续序列](https://leetcode.cn/problems/longest-consecutive-sequence/)

给定一个未排序的整数数组 `nums` ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 `O(n)` 的算法解决此问题。

**示例 1：**

```
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
```

**示例 2：**

```
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
```

**提示：**

- `0 <= nums.length <= 105`
- `-109 <= nums[i] <= 109`

==思路==：

本题的核心是去重——检查以 $x$ 开头的最长序列，就不再需要检查 $x+1$ 开头了（如果 $x+1$ 存在于数组中）。因此使用哈希集合 `unordered_set` 存储数组用于快捷查找，如果 $m-1$ 存在于数组中，就不需要检查 $m$ 了，因为以 $m$ 开头的肯定小于 $m-1$ 开头的。

Code：

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //使用集合去重
        unordered_set<int> st;
        for(auto i:nums){
            st.insert(i);
        }
        int ans = 0;
        for(auto it:nums){
            if(st.count(it-1)) continue;
            int tmp = it;
            while(st.count(++tmp));
            ans = max(ans,tmp-it);
        }
        return ans;
    }
};
```
