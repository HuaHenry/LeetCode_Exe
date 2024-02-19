# [589. N 叉树的前序遍历](https://leetcode.cn/problems/n-ary-tree-preorder-traversal/)



![image-20240219082538012](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240219082538012.png)

![image-20240219082550098](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240219082550098.png)

![image-20240219082602178](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240219082602178.png)

**递归**即可。



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

    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }

    void dfs(Node* nowNode){
        if(!nowNode) return;
        ans.push_back(nowNode->val);
        for(auto i:nowNode->children){
            dfs(i);
        }
        
    }
};
```

