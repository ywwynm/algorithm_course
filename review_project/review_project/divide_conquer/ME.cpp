//#include <iostream>
//using namespace std;
//
//int N;
//int a[200005];
//int tmp[200005];
//long long res;
//
//void divide_and_sort(int s, int e) { // [s, e]
//  if (s >= e) return;
//  int m = (s + e) / 2;
//  divide_and_sort(s, m);
//  divide_and_sort(m + 1, e);
//  //int to = m + 1;
//  //for (int i = s; i <= m; i++) {;
//  //  for (int j = e; j >= to; j--) {
//  //    if (a[i] > 2 * a[j]) {
//  //      res += (m - i + 1) * (j - to + 1);
//  //      to = j + 1;
//  //      break;
//  //    }
//  //  }
//  //}
//  //sort(a + s, a + e + 1); // need to do counting while sorting
//  int tmp_i = s;
//  int i = s, j = m + 1;
//  int pos = -1;
//  while (i <= m && j <= e) {
//    if (a[i] <= a[j]) {
//      tmp[tmp_i++] = a[i++];
//    } else {
//      if (pos == -1) {
//        for (int k = s; k <= m; k++) {
//          if (a[k] > 2 * a[j]) {
//            res += (m - k + 1);
//            pos = k;
//            break;
//          }
//        }
//      } else {
//        for (int k = pos; k <= m; k++) {
//          if (a[k] > 2 * a[j]) {
//            res += (m - k + 1);
//            pos = k;
//            break;
//          }
//        }
//      }
//      tmp[tmp_i++] = a[j++];
//    }
//  }
//  while (i <= m) {
//    tmp[tmp_i++] = a[i++];
//  }
//  while (j <= e) {
//    tmp[tmp_i++] = a[j++];
//  }
//  for (int k = s; k <= e; k++) {
//    a[k] = tmp[k];
//  }
//}
//
//int main() {
//  ios::sync_with_stdio(false);
//  while (cin >> N) {
//    if (N == 0) break;
//    res = 0;
//    for (int i = 0; i < N; i++) cin >> a[i];
//    divide_and_sort(0, N - 1);
//    cout << res << endl;
//  }
//  return 0;
//}