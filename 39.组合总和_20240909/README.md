# [39. 组合总和](https://leetcode.cn/problems/combination-sum/)

![image-20240909171529520](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240909171529520.png)

![image-20240909171538910](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240909171538910.png)

本题非常简单，直接列举所有可能得情况+剪枝即可。

Code：

```cpp
class Solution {
public:
    vector<vector<int>> ans;

    void findAns(vector<int>& candidates, vector<int> listNow, int index, int ans_now, int target){
        if(ans_now > target) return;
        if(ans_now == target){
            ans.push_back(listNow);
            return;
        }
        //开始遍历选择（包括自己）
        for(int i=index;i<candidates.size();i++){
            if(ans_now+candidates[i]>target) continue;
            listNow.push_back(candidates[i]);
            findAns(candidates,listNow,i,ans_now+candidates[i],target);
            listNow.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        findAns(candidates,tmp,0,0,target);
        return ans;
    }
};
```

注意自己也可以继续选择自己。