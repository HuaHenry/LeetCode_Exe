// class Solution {
// public:

//     vector<pair<int,int> > edge_sort[1005];
//     int signalSpeeds;

//     vector<int> dfs_tree(int root,int fa,int len){
//         vector<int> ans_tmp;
//         for(int i=0;i<edge_sort[root].size();i++){
//             if(edge_sort[root][i].first!=fa){
//                 vector<int> tmp = dfs_tree(edge_sort[root][i].first,root,len+edge_sort[root][i].second);
//                 for(int ii=0;ii<tmp.size();ii++){
//                     if((tmp[ii]+edge_sort[root][i].second+len)%signalSpeeds==0){
//                         ans_tmp.push_back(tmp[ii]+edge_sort[root][i].second);
//                     }
//                 }
//             }
//         }
//         if(len%signalSpeeds==0)
//             ans_tmp.push_back(0);
//         return ans_tmp;
//     }

//     vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
//         //重新整理 edges 为邻接表
//         signalSpeeds = signalSpeed;
//         for(int i=0;i<edges.size();i++){
//             edge_sort[edges[i][0]].push_back({edges[i][1],edges[i][2]});
//             edge_sort[edges[i][1]].push_back({edges[i][0],edges[i][2]});
//         }
//         //遍历每个 root 节点
//         int n = edges.size() + 1;
//         vector<int> ans;
//         for(int root=0;root<n;root++){
//             // vector<int> children_num;   //子树中满足要求的节点个数
//             int res=0;
//             int sum=0;
//             for(int i=0;i<edge_sort[root].size();i++){
//                 int child_root = edge_sort[root][i].first;
//                 int child_weig = edge_sort[root][i].second;
//                 //dfs子树
//                 vector<int> child_ans = dfs_tree(child_root,root,child_weig);
//                 // int tmp = 0;
//                 // for(int ii=0;ii<child_ans.size();ii++){
//                 //     if((child_ans[ii]+child_weig)%signalSpeed==0) tmp++;
//                 // }
//                 // children_num.push_back(child_ans.size());

//                 if(i!=0){
//                     res += sum * child_ans.size();
//                 }
//                 sum += child_ans.size();
//             }
//             //计算每个节点的结果

//             // for(int i=0;i<children_num.size();i++){
//             //     for(int j=i+1;j<children_num.size();j++){
//             //         res += children_num[i]*children_num[j];
//             //     }
//             // }
//             ans.push_back(res);
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int> > &edges, int signalSpeed)
    {
        int n = edges.size() + 1;
        vector<vector<pair<int, int> > > g(n);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1], wt = e[2];
            g[x].push_back({y, wt});
            g[y].push_back({x, wt});
        }

        function<int(int, int, int)> dfs = [&](int x, int fa, int sum) -> int
        {
            int cnt = sum % signalSpeed == 0;
            for (auto &[y, wt] : g[x])
            {
                if (y != fa)
                {
                    cnt += dfs(y, x, sum + wt);
                }
            }
            return cnt;
        };

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (auto &[y, wt] : g[i])
            {
                int cnt = dfs(y, i, wt);
                ans[i] += cnt * sum;
                sum += cnt;
            }
        }
        return ans;
    }
};