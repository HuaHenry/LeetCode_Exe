# [429. N 叉树的层序遍历](https://leetcode.cn/problems/n-ary-tree-level-order-traversal/)



![image-20240217155035610](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240217155035610.png)

![image-20240217155043163](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240217155043163.png)



题目中给出每个节点的构造：

```c++
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
```



非常直观的思路就是使用一个**队列**存储上一层节点，一个节点出队的同时将孩子节点都放进队列中。当然，需要记录本层的节点数，避免遍历到新加入的下一层节点中去。至于“一层节点”的存储，可以使用临时变量不定长数组。



Code：（一开始做的思路比较复杂，后来借鉴了官方题解的思路）

```c++
class Solution
{
public:
    vector<vector<int> > levelOrder(Node *root)
    {
        if (!root)
            return {};

        vector<vector<int> > ans;
        queue<Node *> lists;
        lists.push(root);
        while (!lists.empty())
        {
            int cnt = lists.size();
            vector<int> tmp;
            for (int i = 0; i < cnt; i++)
            {
                Node *current = lists.front();
                lists.pop();
                tmp.push_back(current->val);
                for (Node *child : current->children)
                {
                    lists.push(child);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
```

