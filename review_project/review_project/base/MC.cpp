//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//int T, N, M;
//
//int fa[1000005];
//int get_fa(int x) {
//  if (x != fa[x]) {
//    fa[x] = get_fa(fa[x]);
//  }
//  return fa[x];
//}
//
//void union_fa(int x, int y) {
//  int fx = get_fa(x), fy = get_fa(y);
//  if (fx != fy) fa[fx] = fy;
//}
//
//int main() {
//  cin >> T;
//  for (int i = 0; i < T; i++) {
//    cin >> N >> M;
//    memset(fa, -1, sizeof(fa));
//
//    bool ok = false;
//    for (int j = 1; j <= M; j++) {
//      int a, b; cin >> a >> b;
//      if (ok) continue;
//
//      int idx = (a - 1) * N + b;
//      fa[idx] = idx; // idx is opened, change it from -1
//      
//      if (a == 1) { // first row
//        fa[0] = 0;
//        union_fa(idx, 0);
//      }
//      if (a == N) { // last row
//        fa[N * N + 1] = N * N + 1;
//        union_fa(idx, N * N + 1);
//      }
//
//      if (a - 1 >= 1 && fa[idx - N] != -1) { // up
//        union_fa(idx, idx - N);
//      }
//      if (a + 1 <= N && fa[idx + N] != -1) { // down
//        union_fa(idx, idx + N);
//      }
//      if (b - 1 >= 1 && fa[idx - 1] != -1) { // left
//        union_fa(idx, idx - 1);
//      }
//      if (b + 1 <= N && fa[idx + 1] != -1) { // right
//        union_fa(idx, idx + 1);
//      }
//
//      if (fa[0] != -1 && fa[N * N + 1] != -1 && get_fa(0) == get_fa(N * N + 1)) {
//        ok = true;
//        cout << j << endl;
//      }
//    }
//    if (!ok) cout << -1 << endl;
//  }
//  return 0;
//}