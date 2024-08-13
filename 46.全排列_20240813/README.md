# [46. 全排列](https://leetcode.cn/problems/permutations/)

![image-20240813142458329](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240813142458329.png)

思路很简单，直接进行递归回溯和判断即可。

Code：

```cpp
class Solution {
public:
    int len;
    vector<vector<int>> ans;

    void generate_list(vector<int> vis,vector<int>& nums,vector<int> ans_now,int len_now){
        if(len_now==len) ans.push_back(ans_now);
        else{
            len_now++;
            for(int i=0;i<len;i++){
                if(vis[i]==0){
                    vis[i]=1;
                    ans_now.push_back(nums[i]);
                    generate_list(vis,nums,ans_now,len_now);
                    ans_now.pop_back();
                    vis[i]=0;
                }
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        len = nums.size();
        vector<int> vis(len);
        vector<int> ans_now;
        generate_list(vis,nums,ans_now,0);
        return ans;
    }
};
```

