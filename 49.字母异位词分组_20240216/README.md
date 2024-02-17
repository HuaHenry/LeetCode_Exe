# [49. 字母异位词分组](https://leetcode.cn/problems/group-anagrams/)



![image-20240217192821606](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240217192821606.png)



本题可以使用哈希进行简单的归类 —— 由相同字母们组成的不同单词，如果将**字母按顺序排序**后，将是同一个单词。将这个“排序结果”作为哈希表的 `key` 就可以将字母异位词放置到一个哈希表项中。



Code：

```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //思路：按照从小到大的字母排序作为哈希key
        unordered_map<string,vector<string> > mid;
        vector<vector<string> > ans;
        for(int i=0;i<strs.size();i++){
            string tmp = strs[i];
            sort(strs[i].begin(),strs[i].end());
            mid[strs[i]].push_back(tmp);
        }
        for(auto& i:mid){
            ans.push_back(i.second);
        }
        return ans;
    }
};
```



注意哈希表使用 `STL::unordered_map` 实现，遍历哈希表使用引用传递。也可以使用迭代器：`auto i = mp.begin(); i != mp.end(); ++i`。

<img src="http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240217193206431.png" alt="image-20240217193206431" style="zoom:50%;" />