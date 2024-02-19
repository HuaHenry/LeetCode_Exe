# [283. 移动零](https://leetcode.cn/problems/move-zeroes/)

![image-20240219084056847](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240219084056847.png)



**双指针**：

- 第一个指针遍历整个数组
- 第二个指针保留在最后一个非零元素

遍历同时如果第一个指针遇到非零元素就放到第二个指针后面，同时第二个指针++



Code：

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int tmp = -1;
        for(auto i:nums){
            if(i!=0) nums[++tmp] = i;
        }
        //末尾置零
        tmp++;
        for(tmp;tmp<nums.size();tmp++){
            nums[tmp] = 0;
        }
    }
};
```

