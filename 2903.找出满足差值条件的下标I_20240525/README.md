# [2903. 找出满足差值条件的下标 I](https://leetcode.cn/problems/find-indices-with-index-and-value-difference-i/)

![image-20240525132105166](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240525132105166.png)

![image-20240525132112265](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240525132112265.png)

一道非常简单的**暴力搜索**题，直接遍历两个下标进行判断即可。

Code：

```cpp
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        //暴力出奇迹
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(abs(i-j)>=indexDifference && abs(nums[i]-nums[j])>=valueDifference)
                    return vector<int>{i,j};
            }
        }
        return vector<int>{-1,-1};
    }
};
```

