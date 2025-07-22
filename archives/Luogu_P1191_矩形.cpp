// INFO: Tags: 前缀和
//
// 题目描述
// 给出一个 n x n 的矩阵，矩阵中，有些格子被染成白色，有些格子被染成黑色，
// 现要求矩阵中白色**矩形**的数量。
//
// 输入格式
// 第一行，一个整数 n，表示矩形的大小。
// 接下来 n 行，每行 n 个字符，这些字符为 `W` 或 `B`。
// 其中 `W` 表示白格，`B` 表示黑格。
//
// 输出格式
// 一个正整数，为白色矩形数量。
//
// ## 说明/提示
// 对于 30% 的数据，n ≤ 50；
// 对于 100% 的数据，n ≤ 150；

// Sample Input
// 4
// WWBW
// BBWB
// WBWW
// WBWW

// Sample Output
// 19

#include <iostream>
using namespace std;

bool st[151][151];
int s[151][151];

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char x;
      cin >> x;
      st[i][j] = (x == 'W');
      s[i][j] = (st[i][j] ? 1 : 0) + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    }
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int p = i; p <= n; p++) {
        for (int q = j; q <= n; q++) {
          int area = (p - i + 1) * (q - j + 1);
          int sum = s[p][q] - s[i - 1][q] - s[p][j - 1] + s[i - 1][j - 1];
          if (area == sum)
            cnt++;
        }
      }
    }
  }

  cout << cnt << endl;

  return 0;
}
