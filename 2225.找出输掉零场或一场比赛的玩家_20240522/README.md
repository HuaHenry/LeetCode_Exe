# [2225. 找出输掉零场或一场比赛的玩家](https://leetcode.cn/problems/find-players-with-zero-or-one-losses/)

![image-20240522135236693](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240522135236693.png)

![image-20240522135307953](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240522135307953.png)

主要思路就是计算每位球员的输赢次数即可。本人直接使用两个数组存储（存放赢球次数是为了证明该编号球员参加了比赛），也可以如题解使用哈希表存储。

Code：

```cpp
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int win[100005]={0};
        int lose[100005]={0};
        //遍历录入数据
        for(int i=0;i<matches.size();i++){
            win[matches[i][0]]++;
            lose[matches[i][1]]++;
        }
        //计算结果
        vector<int> ans1; vector<int> ans2;
        for(int i=0;i<100005;i++){
            if(win[i]!=0&&lose[i]==0){
                ans1.push_back(i);
            }
            if(lose[i]==1){
                ans2.push_back(i);
            }
        }
        vector<vector<int>> ans;
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};
```

