# [1535. 找出数组游戏的赢家](https://leetcode.cn/problems/find-the-winner-of-an-array-game/)

![image-20240519164323615](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240519164323615.png)

![image-20240519164330449](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240519164330449.png)

本题直接使用`模拟`即可。数据结构上使用**双向队列**和**哈希表**，分别用于模拟数组和存储赢的次数。

本题比较难的一点在于，**不需要真的判断到达`k`次**，因为后续大的数肯定会一直大下去。所以我选择**第一个赢的次数大于 `arr` 尺寸的数**作为结果，通过了本题。

Code：

```cpp
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        // 使用双向队列存储数组
        deque<int> dq;
        int n = arr.size();
        for(int i=0;i<arr.size();i++){
            dq.push_back(arr[i]);
        }
        //使用哈希表存储个数映射关系
        unordered_map<int,int> ump;
        while(true){
            int x1 = dq.front();
            dq.pop_front();
            int x2 = dq.front();
            dq.pop_front();
            int maxn = max(x1,x2), minn = min(x1,x2);
            ump[maxn]++;
            if(ump[maxn]==k||ump[maxn]>n) return maxn;
            dq.push_front(maxn);
            dq.push_back(minn);
        }
    }
};
```

