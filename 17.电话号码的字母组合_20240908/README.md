# [17. 电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)

![image-20240908194313089](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240908194313089.png)

![image-20240908194320021](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240908194320021.png)

简单的回溯问题，直接列举所有情况并回溯即可。

注意 String 类型的操作，在末尾添加字符可以使用 `push_back`，弹出使用 `pop_back`。

Code：

```cpp
class Solution {
public:
    vector<string> ans;

    void dfs(string now_ans, string digits, int index, string info[10]){
        if(index>=digits.size()){
            ans.push_back(now_ans);
            return;
        }
        int find_index = digits[index]-'0';
        for(int i=0;i<info[find_index].size();i++){
            now_ans.push_back(info[find_index][i]);
            dfs(now_ans,digits,index+1,info);
            now_ans.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string info[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        ans.clear();
        if(digits.empty()) return ans;
        dfs("",digits,0,info);
        return ans;
    }
};
```

