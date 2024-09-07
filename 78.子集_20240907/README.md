# [78. 子集](https://leetcode.cn/problems/subsets/)

![image-20240907164451559](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240907164451559.png)

本人使用的递归方法，不断枚举并在每一步存储结果。

Code：

```cpp
class Solution {
public:
    vector<vector<int>> res;

    void ListAns(vector<int>& nums,vector<bool> use,vector<int> tmp,int start){
        res.push_back(tmp);
        for(int i=start;i<nums.size();i++){
            if(!use[i]){
                use[i]=true;
                tmp.push_back(nums[i]);
                ListAns(nums,use,tmp,start+1);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<bool> use(nums.size(),false);
        vector<int> tmp;
        ListAns(nums,use,tmp,0);
        return res;
    }
};
```

题解的思路更为巧妙，将每一个数作为二进制的一位，用 0/1 表示其是否出现。接着枚举二进制代表的十进制数即可。

Code：

```cpp
class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            t.clear();
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    t.push_back(nums[i]);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};
```

