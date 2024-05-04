# [189. 轮转数组](https://leetcode.cn/problems/rotate-array/)

![image-20240504202902487](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240504202902487.png)

本人的解决思路为使用额外的空间存储替换后的数组，并覆盖原数组。index的对应关系见代码：

```c++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(nums[(i-k+10*n)%n]);
        }
        nums = ans;
    }
};
```

另有一种巧妙的思路实现“原地”排序而不需要额外空间，即数组翻转：

![image-20240504203112812](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240504203112812.png)

直接借用题解的代码，也很巧妙：

```c++
class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};
```

