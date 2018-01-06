//#include <iostream>
//#include <string>
//
//using namespace std;
//
//char arr[5010];
//short res[5010][5010]; // use int will lead to TLE
//
//int main() {
//  int len; cin >> len;
//  string str; cin >> str;
//  for (int i = 0; i < len; i++) arr[i] = str[i];
//
//  res[len - 1][len - 1] = 0;
//  for (int i = len - 2; i >= 0; i--) for (int j = i + 1; j < len; j++) {
//    if (i == j) {
//      res[i][j] = 0;
//    } else {
//      short tmp1 = res[i + 1][j];
//      short tmp2 = res[i][j - 1];
//      res[i][j] = tmp1 < tmp2 ? tmp1 : tmp2;
//      if (arr[i] != arr[j]) {
//        res[i][j]++;
//      } else {
//        if (res[i + 1][j - 1] == 0) {
//          res[i][j] = 0;
//        } else {
//          res[i][j] = res[i + 1][j - 1];
//        }
//      }
//    }
//  }
//  cout << res[0][len - 1] << endl;
//  return 0;
//}