/*
  二维DP似乎一直都会TLE
*/

#include <iostream>

using namespace std;

int b, l, n;
int w[1001];
float s[1001];

float min_t[1001][1001];
int sum_w[1001][1001];
int min_s[1001][1001];

float dp(int i, int j) {
  for (int k = i; k < j; k++) {
    if (min_t[i][k] >= 1e20) {
      min_t[i][k] = dp(i, k);
    }
    if (min_t[k + 1][j] >= 1e20) {
      min_t[k + 1][j] = dp(k + 1, j);
    }
    float tmp = min_t[i][k] + min_t[k + 1][j];
    min_t[i][j] = min_t[i][j] < tmp ? min_t[i][j] : tmp;
  }

  if (sum_w[i][j] <= b) {
    float tmp = l * 60.0 / min_s[i][j];
    min_t[i][j] = min_t[i][j] < tmp ? min_t[i][j] : tmp;
  }
  return min_t[i][j];
}

int main() {
  ios::sync_with_stdio(false);
  while (cin >> b >> l >> n) {
    if (b == 0 && l == 0 && n == 0) break;
    for (int i = 0; i < n; i++) {
      cin >> w[i] >> s[i];
      sum_w[i][i] = w[i];
      min_s[i][i] = s[i];
      min_t[i][i] = l * 60.0 / s[i];
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j) min_t[i][j] = 1e20;
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (i != j) {
      sum_w[i][j] = sum_w[i][j - 1] + w[j];
    }
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (i != j) {
      min_s[i][j] = min_s[i][j - 1] < s[j] ? min_s[i][j - 1] : s[j];
    }
    cout << dp(0, n - 1) << endl;
  }
  return 0;
}