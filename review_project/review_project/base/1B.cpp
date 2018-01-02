///*
//
//  1B:棋盘问题
//  
//  总时间限制: 1000ms 内存限制: 65536kB
//  
//  描述
//  在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，
//  请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。
//  
//  输入
//  输入含有多组测试数据。
//  每组数据的第一行是两个正整数，n k，用一个空格隔开，表示了将在一个n*n的矩阵内描述棋盘，以及摆放棋子的数目。 n <= 8 , k <= n
//  当为-1 -1时表示输入结束。
//  随后的n行描述了棋盘的形状：每行有n个字符，其中 # 表示棋盘区域， . 表示空白区域（数据保证不出现多余的空白行或者空白列）。
//  
//  输出
//  对于每一组数据，给出一行输出，输出摆放的方案数目C （数据保证C<2^31）。
//  
//  样例输入
//  2 1
//  #.
//  .#
//  4 4
//  ...#
//  ..#.
//  .#..
//  #...
//  -1 -1
//  
//  样例输出
//  2
//  1
//
//*/
//
//
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//int board[8][8];
//bool cpc[8]; // can_put_col
//int n, k;
//
//int count(int i, int chess_to_put) {
//  if (chess_to_put == 0) return 0;
//  int c = 0;
//  for (; i < n; i++) for (int j = 0; j < n; j++) if (cpc[j] && board[i][j] == 1)  {
//    board[i][j] = 0;
//    cpc[j] = false;
//
//    if (chess_to_put == 1) {
//      c++;
//    } else {
//      c += count(i + 1, chess_to_put - 1);
//    }
//
//    board[i][j] = 1;
//    cpc[j] = true;
//  }
//  return c;
//}
//
//int main() {
//  ios::sync_with_stdio(false);
//  while (cin >> n >> k) {
//    if (n == -1 && k == -1) break;
//    memset(cpc, true, sizeof(cpc));
//    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
//      char c; cin >> c;
//      board[i][j] = c == '#' ? 1 : 0;
//    }
//    cout << count(0, k) << endl;
//  }
//  return 0;
//}