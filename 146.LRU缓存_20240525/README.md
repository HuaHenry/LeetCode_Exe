# [146. LRU 缓存](https://leetcode.cn/problems/lru-cache/)

![image-20240525140524682](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240525140524682.png)

![image-20240525140531113](http://henry-typora.oss-cn-beijing.aliyuncs.com/img/image-20240525140531113.png)

本题由于各种操作需要 $O(1)$ 的时间复杂度，故使用大量额外空间存储。

使用**指针**实现对元素的**直接访问**，思路见代码（一看就懂）。

Code：

```cpp
class LRUCache {
public:

    struct cache{
        int index;
        int value;
        int del;
    };

    cache* cacheList[10005]={NULL};    // index 和 cache* 的对应关系
    queue<cache*> cachequeue;   // 存储LRU空闲表
    int size;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cacheList[key]!=NULL){
            //找到
            //移动位置
            cacheList[key]->del++;
            cap++;
            size++;
            cachequeue.push(cacheList[key]);
            return cacheList[key]->value;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(cacheList[key]!=NULL){
            //已经存在
            cacheList[key]->value = value;
            cacheList[key]->del++;
            cap++;
            size++;
            cachequeue.push(cacheList[key]);
        }
        else{   
            //需要插入
            //判断是否还有空闲
            while(size>=cap){
                //换出
                cache* tmp = cachequeue.front();
                if(tmp->del!=0){
                    size--;
                    cap--;
                    tmp->del--;
                    cachequeue.pop();
                }
                else{
                    size--;
                    cacheList[tmp->index] = NULL;
                    cachequeue.pop();
                    delete(tmp);
                }
            }
            //插入
            cache* NewCache = new cache;
            NewCache->index = key;
            NewCache->value = value;
            NewCache->del = 0;
            cacheList[key] = NewCache;
            cachequeue.push(NewCache);
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

