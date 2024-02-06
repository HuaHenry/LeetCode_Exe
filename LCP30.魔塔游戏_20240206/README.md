# [LCP 30. 魔塔游戏](https://leetcode.cn/problems/p0NxJO/)

2024/02/06



![image-20240206183848926](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240206183848926.png)

很不巧踩坑了（

出于贪心的思路，我一开始的思路是——模拟维护双端队列，一遇到让当前血量小于等于0的直接放到队列末尾（`pop_front` +`push_back`），直到队列为空。为了防止最后有几个负值被交替循环替换，提前遍历一遍计算所有数的总和，就能预先判断这个队列是否完成任务（不能就直接返回-1）

Wrong Code：

```cpp
/* 典型错误(doge) */
// class Solution {
// public:
//     int magicTower(vector<int>& nums) {
//         //先判断是否可以通过
//         int n = nums.size(),sum = 0,cnt = 0;
//         deque<int> dq;  //双向队列模拟
//         for(int i=0;i<n;i++){
//             sum += nums[i];
//             dq.push_back(nums[i]);
//         }
//         if(sum<0) return -1;
//         //一定可以通过的情况，不用考虑循环替换
//         sum = 0;
//         while(!dq.empty()){
//             int fnt = dq.front();
//             dq.pop_front();
//             if(sum + fnt < 0){
//                 //替换至末尾
//                 dq.push_back(fnt);
//                 cnt++;
//             }
//             else if(sum + fnt == 0){
//                 //如果是最后一个房间可以
//                 if(!dq.empty()){
//                     //替换至末尾
//                     dq.push_back(fnt);
//                     cnt++;
//                 }
//             }
//             else{
//                 sum += fnt;
//             }
//         }
//         return cnt;
//     }
// };
```



上面方法可以实现，但是不符合“移动次数最小”，因为“血量一变成非正数的就移动”的策略，如果前面有一个**巨大无比的负值**，倒不如先移动这个负值，那么后面就可以省去数次的“小移动”

如 200，-150，-60，-60，-60，200

- 如果按照上面的策略，那么将移动-60、-60、-60，移动三次
- 但是如果移动-150，那么三个-60都不用移动，只需要移动一次



所以需要变更一下贪心的思路——当血量非正，移动的是**前面最负的那个数**。这样就一劳永逸保证了后面少移动几次。

故可以跟随遍历，维护**小根堆（优先队列）**，这个优先队列存储的是从开始遍历以来，遇到的**负值**。

如果一旦血量非正，从优先队列找到**小根堆堆顶**，**补回血量**，并**从小根堆删除**（表示需要移到后面去），表示移动的是当前遇到过最负的负值。



更多细节看代码（官方题解用了`delay`存储被移动的变量和，用于最终判断是否能完成，本人觉得直接求和更为直观）

Code：

```c++
class Solution {
public:
    int magicTower(vector<int>& nums) {
        //先判断是否可以通过
        long long int n = nums.size(),sum = 1,cnt = 0,cur = 1;
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0;i<n;i++){
            sum += nums[i];
            cur += nums[i];
            if(nums[i]<0)
                q.push(nums[i]);
            //如果分数为非正，小根堆堆顶回补
            if(cur <= 0){
                cnt++;
                cur -= q.top();
                q.pop();
            }
        }
        if(sum<=0) return -1;
        return cnt;
    }
};
```



<img src="http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240206185041043.png" alt="image-20240206185041043" style="zoom:50%;" />