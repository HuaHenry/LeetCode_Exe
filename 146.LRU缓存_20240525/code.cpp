class LRUCache
{
public:
    struct cache
    {
        int index;
        int value;
        int del;
    };

    cache *cacheList[10005] = {NULL}; // index 和 cache* 的对应关系
    queue<cache *> cachequeue;        // 存储LRU空闲表
    int size;
    int cap;

    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (cacheList[key] != NULL)
        {
            // 找到
            // 移动位置
            cacheList[key]->del++;
            cap++;
            size++;
            cachequeue.push(cacheList[key]);
            return cacheList[key]->value;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        if (cacheList[key] != NULL)
        {
            // 已经存在
            cacheList[key]->value = value;
            cacheList[key]->del++;
            cap++;
            size++;
            cachequeue.push(cacheList[key]);
        }
        else
        {
            // 需要插入
            // 判断是否还有空闲
            while (size >= cap)
            {
                // 换出
                cache *tmp = cachequeue.front();
                if (tmp->del != 0)
                {
                    size--;
                    cap--;
                    tmp->del--;
                    cachequeue.pop();
                }
                else
                {
                    size--;
                    cacheList[tmp->index] = NULL;
                    cachequeue.pop();
                    delete (tmp);
                }
            }
            // 插入
            cache *NewCache = new cache;
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