///*
//
//  1C:Til the Cows Come Home
//  总时间限制: 1000ms 内存限制: 65536kB
//
//  描述
//  Bessie is out in the field and wants to get back to the barn to get as much sleep as possible before Farmer John wakes her 
//  for the morning milking. Bessie needs her beauty sleep, so she wants to get back as quickly as possible.
//  
//  Farmer John's field has N (2 <= N <= 1000) landmarks in it, uniquely numbered 1..N. Landmark 1 is the barn; the apple tree 
//  grove in which Bessie stands all day is landmark N. Cows travel in the field using T (1 <= T <= 2000) bidirectional cow-trails 
//  of various lengths between the landmarks. Bessie is not confident of her navigation ability, so she always stays on a trail 
//  from its start to its end once she starts it.
//  
//  Given the trails between the landmarks, determine the minimum distance Bessie must walk to get back to the barn. It is guaranteed 
//  that some such route exists.
//  输入
//  * Line 1: Two integers: T and N
//  
//  * Lines 2..T+1: Each line describes a trail as three space-separated integers. The first two integers are the landmarks between 
//  which the trail travels. The third integer is the length of the trail, range 1..100.
//
//  输出
//  * Line 1: A single integer, the minimum distance that Bessie must travel to get from landmark N to landmark 1.
//
//  样例输入
//  5 5
//  1 2 20
//  2 3 30
//  3 4 20
//  4 5 20
//  1 5 100
//
//  样例输出
//  90
//
//  提示
//  INPUT DETAILS:
//  
//  There are five landmarks.
//  
//  OUTPUT DETAILS:
//  
//  Bessie can get home by following trails 4, 3, 2, and 1.
//
//  来源
//  USACO 2004 November
//
//*/
//
//#include <iostream>
//#include <cstring>
//#include <queue>
//
//using namespace std;
//
//const int MAX_NODE = 3000;
//const int MAX_EDGE = 8000;
//
//const int INF = 0x7f7f7f7f;
//
//struct edge {
//  int v, next, w;
//} E[MAX_EDGE];
//
//int nodes[MAX_NODE];
//int edge_count;
//
//void add_edge(int u, int v, int w) {
//  E[edge_count] = edge { v, nodes[u], w };
//  nodes[u] = edge_count++;
//}
//
///* 自己默写出来的贼开心^_^ */
//int spfa(int S, int T) {
//  int dis[MAX_NODE];
//  memset(dis, INF, sizeof(dis));
//  bool in_q[MAX_NODE] = { false };
//  queue<int> q;
//  q.push(S);
//  dis[S] = 0;
//  in_q[S] = true;
//  while (!q.empty()) {
//    int u = q.front(); q.pop();
//    in_q[u] = false;
//    for (int i = nodes[u]; i != -1; i = E[i].next) {
//      edge e = E[i];
//      int v = E[i].v;
//      if (dis[v] > dis[u] + e.w) {
//        dis[v] = dis[u] + e.w;
//        if (!in_q[v]) {
//          q.push(v);
//          in_q[v] = true;
//        }
//      }
//    }
//  }
//  return dis[T] == INF ? -1 : dis[T];
//}
//
//int main() {
//  memset(nodes, -1, sizeof(nodes));
//  edge_count = 0;
//  ios::sync_with_stdio(false);
//  int T, N;
//  cin >> T >> N;
//  for (int i = 0; i < T; i++) {
//    int u, v, w; cin >> u >> v >> w;
//    add_edge(u, v, w);
//    add_edge(v, u, w);
//  }
//  cout << spfa(N, 1) << endl;
//  return 0;
//}