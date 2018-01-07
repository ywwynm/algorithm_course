//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int MAX_NODE = 103;
//const int MAX_EDGE = 11000;
//
//const int INF = 0x7f7f7f7f;
//
//struct edge {
//  int u, v, next, w;
//  bool operator < (const edge &ano) {
//    return w < ano.w;
//  }
//} E[MAX_EDGE];
//
//int nodes[MAX_NODE];
//int edge_count = 0;
//
//void add_edge(int u, int v, int w) {
//  E[edge_count] = edge{ u, v, nodes[u], w };
//  nodes[u] = edge_count++;
//}
//
//int fa[MAX_NODE];
//int get_fa(int x) {
//  if (fa[x] != x) {
//    fa[x] = get_fa(fa[x]);
//  }
//  return fa[x];
//}
//
//bool used[MAX_EDGE];
//
//int kruskal(int del_idx, int n, int m, bool set_used) {
//  for (int i = 1; i <= n; i++) fa[i] = i;
//  int res = 0;
//  for (int i = 0; i < m; i++) {
//    if (i == del_idx) continue;
//    edge e = E[i];
//    int u = e.u, v = e.v;
//    int fu = get_fa(u), fv = get_fa(v);
//    if (fu != fv) {
//      if (set_used) used[i] = true;
//      res += e.w;
//      fa[fu] = fv;
//    }
//  }
//  int k = get_fa(1);
//  for (int i = 1; i <= n; i++) if (get_fa(i) != k) return -1;
//  return res;
//}
//
//int main() {
//  ios::sync_with_stdio(false);
//  int t; cin >> t;
//  for (int i = 0; i < t; i++) {
//    memset(nodes, -1, sizeof(nodes));
//    memset(used, false, sizeof(used));
//    edge_count = 0;
//    int n, m; cin >> n >> m;
//    for (int j = 0; j < m; j++) {
//      int xi, yi, wi; cin >> xi >> yi >> wi;
//      add_edge(xi, yi, wi);
//    }
//    sort(E, E + m);
//    int ans = kruskal(-1, n, m, true);
//    bool not_unique = false;
//    for (int j = 0; j < m; j++) {
//      if (used[j]) {
//        int ans2 = kruskal(j, n, m, false);
//        if (ans == ans2) {
//          cout << "Not Unique!" << endl;
//          not_unique = true;
//          break;
//        }
//      }
//    }
//    if (!not_unique) {
//      cout << ans << endl;
//    }
//  }
//  return 0;
//}