# [41. 缺失的第一个正数](https://leetcode.cn/problems/first-missing-positive/)

![image-20240505165003127](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240505165003127.png)

![image-20240505165012199](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240505165012199.png)



由于限制在于**时间复杂度O(N)**和**常数级空间复杂度**。可以考虑使用输入原数组来实现原地的判断。

先验知识：第一个正整数只存在于 `[1,N+1]`，自行推导可以获得。因此可以使用原数组构建一个另类的哈希表，使用负值表示是否有数据在此存储：

![image-20240505165225808](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240505165225808.png)

Code：

```c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //使用数组映射的方法，遍历查看 [1,N]
        int n = nums.size();
        //首先遍历保证数组内元素都是正数
        for(int i=0;i<n;i++){
            if(nums[i]<1 || nums[i]>n){
                nums[i] = n+1;
            }
        }
        for(int i=0;i<n;i++){
            if(abs(nums[i])>=1 && abs(nums[i])<=n){
                nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                return i+1;
            }
        }
        return n+1;
    }
};
```

