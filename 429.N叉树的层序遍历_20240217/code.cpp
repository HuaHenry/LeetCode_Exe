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