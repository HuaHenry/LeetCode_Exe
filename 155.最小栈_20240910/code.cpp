class MinStack
{
public:
    stack<pair<int, int> > ans; // pair<节点值，元素以下最小值>

    MinStack()
    {
        while (!(ans.empty()))
            ans.pop();
    }

    void push(int val)
    {
        if (ans.empty() || ans.top().second >= val)
            ans.push(pair<int, int>{val, val});
        else
            ans.push(pair<int, int>{val, ans.top().second});
    }

    void pop()
    {
        ans.pop();
    }

    int top()
    {
        return ans.top().first;
    }

    int getMin()
    {
        return ans.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */