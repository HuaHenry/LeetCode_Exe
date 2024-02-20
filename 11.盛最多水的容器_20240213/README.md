# [11. 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/)



![image-20240220210054347](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240220210054347.png)

![image-20240220210119687](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240220210119687.png)

非常巧妙的思路：

假设有左右两块板，若将短的那块板用靠内的一块代替（内移），那么容量结果可能会变大也可能会变小；但是如果内移长的那块，那么一定会变小或不变。（限制因素短板还在）

因此初始化两个指针在左右两端，不断内移短板，更新最大值即可。

可以参考视频：[盛最多水的容器 接雨水_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1Qg411q7ia/?vd_source=c2387af39e36e5591e58f7a0cd21bf21)



Code：

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int ans = 0;
        while(left!=right){
            ans = max(ans,(right-left)* min(height[left],height[right]));
            if(height[left]<=height[right]) left++;
            else right--;
        }
        return ans;
    }
};
```

