# [590. N 叉树的后序遍历](https://leetcode.cn/problems/n-ary-tree-postorder-traversal/)

<img src="http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240219081809096.png" alt="image-20240219081809096" style="zoom:50%;" />

<img src="http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240219081843270.png" alt="image-20240219081843270" style="zoom:50%;" />



思路非常简单，**递归**即可。



Code：

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    vector<int> ans;

    vector<int> postorder(Node* root) {
        dfs(root);
        return ans;
    }

    void dfs(Node* nowNode){
        if(!nowNode) return;
        for(auto i:nowNode->children){
            dfs(i);
        }
        ans.push_back(nowNode->val);
    }


};
```

