#include <iostream>

using namespace std;

int b, l, n;
int w[1001];
float s[1001];

float min[1001][1001];

float dp(int i, int j) {
  for (int k = i; k < j; k++) {
    if (min[i][k] == -1) min[i][k] = dp(i, k);
    if (min[k + 1][j] == -1) min[k + 1][j] = dp(k + 1, j);
    float tmp = min[i][k] + min[k + 1][j + 1];
    min[i][j] = min[i][j] < tmp ? min[i][j] : tmp;
  }
  return min[i][j];
}

int main() {
  while (cin >> b >> l >> n) {
    if (b == 0 && l == 0 && n == 0) break;
    for (int i = 0; i < n; i++) {
      cin >> w[i] >> s[i];
      min[i][i] = l * 60 / s[i];
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j) min[i][j] = -1;
    cout << dp(0, 2) << endl;
  }
  return 0;
}