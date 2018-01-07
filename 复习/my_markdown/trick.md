# 实现与 trick

## head

``` C++
#include <queue> // queue, priority_queue
#include <functional> // 最小堆需要
#include <deque> // 双向队列
#include <cstring> // for memset
#include <iomanip> // 格式化输出
#include <limits.h> // INT_MAX 等
#include <algorithm> // sort, min(), max()

const int INF = 0x3f3f3f3f; // 1061109567，和 MAX_INT 处于同一数量级，且 * 2 后仍然在 MAX_INT 范围内
const int INF_DOUBLE = 1e20;

typedef long long LL;

// #include <iostream> && using namespace std
typedef pair<int, int> PII;

```

## 数据处理

``` C++
memset(arr, 0x3F, sizeof(arr));

int arr[10];
sort(arr, arr + 7); // 对 arr[0]~arr[6] 升序排序

bool cmp(const int &a, const int &b) return a > b;
sort(arr, arr + 7, cmp); // 对 arr[0]~arr[6] 降序排序

struct edge {
  int v, next, w;
  bool operator < (const edge& ano) const {
    return w < ano.w; // 注意这里不能是 <=
  }
} E[10];
sort(edge, edge + 10); // 对 E[0]~E[9] 按照 w 升序排序

bool cmp_edge(const edge &a, const edge &b) return a.w > b.w;
sort(edge, edge + 10, cmp_edge); // 对 E[0]~E[9] 按照 w 降序排序
```

## 输入输出

``` C++
ios::sync_with_stdio(false);

freopen("in.txt", "r", stdin); // 如果一道题目反复改，测试数据又不少，可以用这个降低修改-验证成本...

while (cin >> a) { // do stuff }

while (true) {
  char ch = cin.get(); // 没有给定输入长度的话，可以一个一个读
  if (ch == '\n') break;
  int x; cin >> x; // 注意不要用 x = ch - '0'，因为 cin.get() 每次只能读 1 个字符，而 x 可能是二位数或者更多位数
  // do stuff
}

string s;
getline(cin, s); // 一次读一行，遇到 \n 才会停止读取

cout << fixed << setprecision(1) << ans; // 输出小数点后 1 位
```

## C 风格的输入输出

```C
// scanf, printf 不用引入头文件

scanf("%lld", &a); // long long
scanf("%f", &a); // float
scanf("%lf", &a); // double

char a[255];
scanf("%s", a); // string
printf("%s", a);

while (~scanf("%d", &a)) { // do stuff }

printf("%6d", a); // 左边补空格，a = 1024, 显示 1024
printf("%06d", a); // 左边补 0，a = 1024, 显示 001024
printf("%.1f", a); // 小数点后 1 位
```

## 数据结构

### 并查集 union_find

典型题目: **MC、Kruskal 最小生成树**

关键代码: 

``` C++
int fa[N];
int get_fa(int x) { // 找到 x 的类别
  if (x != fa[x]) {
    fa[x] = get_fa(fa[x]);
  }
  return fa[x];
}

void union_fa(int x, int y) { // 将 x 和 y 归并为一类
  int fx = get_fa(x), fy = get_fa(y);
  if (fx != fy) fa[fx] = fy;
}

// 初始化时，fa可以为-1，或者为index(读取数据时的下标)
```

### 优先队列 priority_queue

典型题目: 2B、Prim 最小生成树

关键代码:

```C++
#include <vector>
#include <queue>
#include <functional>

priority_queue<int, vector<int>, less<int> > max_heap;
priority_queue<int, vector<int>, greater<int> > min_heap;

// 如果优先队列里存放的是自定义结构体
struct edge {
  int v, next, w;
  bool operator < (const edge& ano) const {
    return w < ano.w;
  }
};
priority_queue<edge> heap_max_w;
```