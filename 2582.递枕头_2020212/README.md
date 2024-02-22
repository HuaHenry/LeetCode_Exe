# [2582. 递枕头](https://leetcode.cn/problems/pass-the-pillow/)



![image-20240222144847836](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240222144847836.png)

![image-20240222144858224](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240222144858224.png)

**简单**！（好久没遇到那么简单的题了以至于开始琢磨怎么一行写完）

可以通过模拟来实现过程，但是实际上可以通过数学计算一步算得：

- time/(n-1)如果是偶数，那么正在“正向传递”
- 如果是奇数，那么正在“反向传递”

确定了传递方向，那么可以根据余数确定具体位置啦。



Code：

```cpp
class Solution {
public:
    int passThePillow(int n, int time) {
        return ((time/(n-1))%2==0?1+time%(n-1):n-time%(n-1));
    }
};
```

