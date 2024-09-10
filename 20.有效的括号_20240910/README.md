# [20. 有效的括号](https://leetcode.cn/problems/valid-parentheses/)

![image-20240910145637101](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240910145637101.png)

![image-20240910145645752](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240910145645752.png)

非常简单的**栈**类型的题目，模拟出栈入栈即可。注意细节不要忽视。

Code：

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        for(auto i:s){
            if(i=='(' || i=='[' || i=='{') charStack.push(i);
            else if(charStack.empty()) return false;
            else if((charStack.top()-i)*(charStack.top()-i)==1 || (charStack.top()-i)*(charStack.top()-i)==4) charStack.pop();
            else return false;
        }
        if(charStack.empty()) return true;
        return false;
    }
};
```

