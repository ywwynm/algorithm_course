#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;

const int MAX_NODE = 103;
const int MAX_EDGE = 11000;

const int INF = 0x7f7f7f7f;

struct edge {
  int v, next, w;
} E[MAX_EDGE];

int nodes[MAX_NODE];
int edge_count = 0;

void add_edge(int u, int v, int w) {
  E[edge_count] = edge { v, nodes[u], w };
  nodes[u] = edge_count++;
}

int levels[103];

int spfa(int S, int T, int level_s, int level_t) {
  int dis[MAX_NODE];
  memset(dis, INF, sizeof(dis));
  bool inq[MAX_NODE] = { false };
  queue<int> q;
  q.push(S);
  dis[S] = 0;
  inq[S] = true;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    inq[u] = false;
    for (int i = nodes[u]; i != -1; i = E[i].next) {
      int v = E[i].v;
      if (dis[v] > dis[u] + E[i].w && level_s <= levels[v] && levels[v] <= level_t) {
        dis[v] = dis[u] + E[i].w;
        if (!inq[v]) {
          q.push(v);
          inq[v] = true;
        }
      }
    }
  }
  return dis[T];
}

int main() {
  ios::sync_with_stdio(false);
  memset(nodes, -1, sizeof(nodes));
  int M, N; cin >> M >> N;
  for (int i = 1; i <= N; i++) {
    int P, L, X; cin >> P >> L >> X;
    levels[i] = L;
    add_edge(N + 1, i, P);
    for (int j = 0; j < X; j++) {
      int T, V; cin >> T >> V;
      add_edge(T, i, V);
    }
  }
  int res = INF;
  int L = levels[1];
  for (int i = L - M; i <= L; i++) { // this problem is ridiculous...
    int tmp = spfa(N + 1, 1, i, i + M);
    if (tmp < res) res = tmp;
  }
  cout << res << endl;
  return 0;
}