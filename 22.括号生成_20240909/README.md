# [22. 括号生成](https://leetcode.cn/problems/generate-parentheses/)

![image-20240909173705852](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240909173705852.png)

本人使用的枚举的方法，添加规则为最左边添加，或遇到左括号就在右边添加一对闭合的括号。这种做法确实可以保证解集的完备性，不过时间占用较多。

Code：

```cpp
class Solution {
public:
    vector<string> ans;
    unordered_set<string> ans_set;

    void dfs(string ans_now, int n, int index){
        if(index>n){
            if(ans_set.count(ans_now)) return;
            ans.push_back(ans_now);
            ans_set.insert(ans_now);
            return;
        }
        //首先放在最前面
        dfs("()"+ans_now,n,index+1);
        //找左括号的右侧插入
        for(int i=0;i<ans_now.size();i++){
            if(ans_now[i]=='('){
                string leftSide = ans_now.substr(0,i+1);
                string rightSide = ans_now.substr(i+1);
                string tmp = leftSide + "()" + rightSide;
                dfs(tmp,n,index+1);
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs("",n-1,0);
        return ans;
    }
};
```

