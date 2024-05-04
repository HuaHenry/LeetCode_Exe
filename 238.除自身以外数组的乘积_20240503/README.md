# [238. 除自身以外数组的乘积](https://leetcode.cn/problems/product-of-array-except-self/)

![image-20240504205134830](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240504205134830.png)

![image-20240504205141041](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240504205141041.png)

我的思路没有达到 `O(1)` 的空间复杂度，不过也可以通过本题：

分别计算并存储 “**前缀积**” 和 “**后缀积**” ，最后结果通过相乘前缀积和后缀积即可。Code：

```c++
class Solution {
public:
    int pre[100005]={-1};
    int aft[100005]={-1};

    vector<int> productExceptSelf(vector<int>& nums) {
        //首先求前缀积
        vector<int> ans;
        int n = nums.size();
        pre[0] = 1;
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] * nums[i-1];
        }
        //接着求后缀积
        aft[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            aft[i] = aft[i+1] * nums[i+1];
        }
        //求最终结果
        for(int i=0;i<n;i++){
            ans.push_back(pre[i]*aft[i]);
        }
        return ans;
    }
};
```

题解中更巧妙的方法是使用结果数组 ans 存放前缀积，后缀积在前缀积的基础上动态构建，不使用额外的空间，非常巧妙。题解代码：

```c++
class Solution {
public:
    int pre[100005]={-1};
    int aft[100005]={-1};

    vector<int> productExceptSelf(vector<int>& nums) {
        //首先求前缀积
        vector<int> ans;
        int n = nums.size();
        pre[0] = 1;
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] * nums[i-1];
        }
        //接着求后缀积
        aft[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            aft[i] = aft[i+1] * nums[i+1];
        }
        //求最终结果
        for(int i=0;i<n;i++){
            ans.push_back(pre[i]*aft[i]);
        }
        return ans;
    }
};
```

