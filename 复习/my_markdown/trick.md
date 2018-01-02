# 实现与 trick

## head

``` C++
#include <queue> // queue, priority_queue
#include <deque> // 双向队列
#include <cstring> // for memset

const int INF = 0x3f3f3f3f; // 1061109567，和 MAX_INT 处于同一数量级，且 * 2 后仍然在 MAX_INT 范围内

typedef pair<int, int> PII;

```

## 数据处理

``` C++
memset(arr, 0x3F, sizeof(arr));

ios::sync_with_stdio(false);

freopen("in.txt", "r", stdin); // 如果一道题目反复改，测试数据又不少，可以用这个降低修改-验证成本...
```

## 数据结构

### 并查集 union_find

### 优先队列 priority_queue