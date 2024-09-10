# [155. 最小栈](https://leetcode.cn/problems/min-stack/)

![image-20240910151053763](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240910151053763.png)

![image-20240910151106053](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240910151106053.png)

本题非常巧妙：常数级复杂度取栈中最小值，每个栈元素另存一个当前元素以下所有元素的最小值即可。入栈时，入栈元素的最小值属性需要将自身和原栈顶元素的最小值属性比较。因此可以保证栈中每一个元素都存储这个元素以下所有元素的最小值、栈顶元素存储的是整个栈的最小值。

Code：

```cpp
class MinStack {
public:
    stack<pair<int,int>> ans;   // pair<节点值，元素以下最小值>

    MinStack() {
        while(!(ans.empty())) ans.pop();
    }
    
    void push(int val) {
        if(ans.empty() || ans.top().second>=val) ans.push(pair<int,int>{val,val});
        else ans.push(pair<int,int>{val,ans.top().second});
    }
    
    void pop() {
        ans.pop();
    }
    
    int top() {
        return ans.top().first;
    }
    
    int getMin() {
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
```

