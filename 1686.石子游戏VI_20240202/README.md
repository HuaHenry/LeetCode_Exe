# [1686. 石子游戏 VI](https://leetcode.cn/problems/stone-game-vi/)

2024/2/2



![image-20240202131522648](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240202131522648.png)

![image-20240202131534432](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240202131534432.png)

**提示：**

- `n == aliceValues.length == bobValues.length`
- `1 <= n <= 105`
- `1 <= aliceValues[i], bobValues[i] <= 100`



**贪心 + 排序**的解决思路

主要想法为，这里两位玩家的“**最优**策略”都是兼顾损人和利己的策略：

假设有两个石子 $x,y$，alice 和 bob 各选一个，那么他们的分数差就可以有 $a[x]-b[y]$ 和 $a[y]-b[x]$ 两种情况。对于 alice 肯定选分数差最大的，也就是如果 $(a[x]-b[y])-(a[y]-b[x])=(a[x]+b[x])-(a[y]+b[y])>0$，那么 alice 一定选取x，否则选取y。对于 bob 也是同理。

那么他们的选择实际上就是 $a[i]+b[i]$ 的降序排序问题，排在前面的依次被选取。



具体代码实现使用 `pair<int,int>` 存储 `<相加之和，index>`，其中相加之和用于降序排序，index用于计算最后分数时定位石子。

降序排序基于sort（默认升序）有两种实现方法：

- 方法1：（本人采用）使用**反向迭代器**改变顺序，即`rbegin()`和`rend()`
- 方法2：自定义排序函数实现，返回bool值，作为sort函数的第三参数



Code：

```c++
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        //先对双方认定的价值相加并进行排序，得到价值和的降序排序
        vector<pair<int,int> > valuesSort;
        for(int i=0;i<aliceValues.size();i++){
            valuesSort.push_back(pair<int,int>{aliceValues[i]+bobValues[i],i});
        }
        //使用反向迭代器降序排序
        sort(valuesSort.rbegin(),valuesSort.rend());
        //开始计算双方得分
        int alice=0,bob=0;
        for(int i=0;i<aliceValues.size();i++){
            if(i%2){
                //bob
                bob += bobValues[valuesSort[i].second];
            }
            else{
                //alice
                alice += aliceValues[valuesSort[i].second];
            }
        }
        return (bob==alice?0:(bob>alice?-1:1));
    }
};
```