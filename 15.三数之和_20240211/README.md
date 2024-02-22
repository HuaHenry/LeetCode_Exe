# [15. 三数之和](https://leetcode.cn/problems/3sum/)

![image-20240222151810360](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240222151810360.png)

![image-20240222151820772](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240222151820772.png)

经典的**双指针**问题

但是这里有三个变量，那么思路先排序，遍历并**固定一个**，剩余两个使用**双指针逼近**。

关于判断重复，由于已经排好序，那么在双指针逼近的时候判断下一位置值是否相同即可。具体见代码。



Code：

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //三个元素 i,j,k，遍历i，双指针枚举j和k
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            int left = i+1 , right = n-1;
            if(nums[i]>0) return ans;
            while(left<right){
                if(nums[left]+nums[right]+nums[i]>0) right--;
                else if(nums[left]+nums[right]+nums[i]<0) left++;
                else{
                    cout<<nums[i]<<' '<<nums[left]<<' '<<nums[right]<<endl;
                    //==0
                    //判断下一位置是否存在重复
                    if(left!=right-1&&(nums[left+1]==nums[left])){
                        left++;
                        continue;
                    }
                    else if(left!=right-1&&(nums[right-1]==nums[right])){
                        right--;
                        continue;
                    }
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    ans.push_back(tmp);
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};
```

