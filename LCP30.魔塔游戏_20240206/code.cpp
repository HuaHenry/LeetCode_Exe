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

// 改改改
class Solution
{
public:
    int magicTower(vector<int> &nums)
    {
        // 先判断是否可以通过
        long long int n = nums.size(), sum = 1, cnt = 0, cur = 1;
        priority_queue<int, vector<int>, greater<int> > q;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            cur += nums[i];
            if (nums[i] < 0)
                q.push(nums[i]);
            // 如果分数为非正，小根堆堆顶回补
            if (cur <= 0)
            {
                cnt++;
                cur -= q.top();
                q.pop();
            }
        }
        if (sum <= 0)
            return -1;
        return cnt;
    }
};
