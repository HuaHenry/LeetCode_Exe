class Solution {
public:
    int n;
    priority_queue<pair<int,int> > pq;

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        n = nums.size();
        //将首次元素录入大根堆
        for(int i=0;i<k;i++){
            pq.push(pair{nums[i],i});
        }
        vector<int> ans = {pq.top().first};

        //维护大根堆
        for(int i=k;i<n;i++){
            pq.push(pair{nums[i],i});
            while(pq.top().second<=i-k){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;

    }
};