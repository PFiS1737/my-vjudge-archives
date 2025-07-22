// INFO: Tags: DFS
//
// 题目描述
// 机器猫被困在一个矩形迷宫里。迷宫可以视为一个 n x m 矩阵，每个位置要么是空地，要么是墙。
// 机器猫只能从一个空地走到其上、下、左、右的空地。
// 机器猫初始时位于 (1, 1) 的位置，问能否走到 (n, m) 位置。
//
// 输入格式
// 第一行，两个正整数 n, m。
// 接下来 n 行，输入这个迷宫。每行输入一个长为 m 的字符串，`#` 表示墙，`.` 表示空地。
//
// 输出格式
// 仅一行，一个字符串。如果机器猫能走到 (n, m)，则输出 `Yes`；否则输出 `No`。
//
// 说明/提示
// 对于 100% 的数据，保证 1 <= n, m <= 100，且 (1, 1) 和 (n, m) 均为空地。

// Sample Input
// 3 5
// .##.#
// .#...
// ...#.

// Sample Output
// Yes

#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  bool mas[n + 1][m + 1]; // NOLINT
  memset(mas, false, sizeof(mas));

  char x;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> x;
      mas[i][j] = (x == '.');
    }
    cin.ignore();
  }

  stack<pair<int, int>> q;
  q.push({1, 1});

  bool visited[n + 1][m + 1]; // NOLINT
  memset(visited, false, sizeof(visited));

  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  while (!q.empty()) {
    int x = q.top().first;
    int y = q.top().second;
    q.pop();
    visited[x][y] = true;
    if (x == n && y == m) {
      cout << "Yes" << endl;
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && mas[nx][ny] && !visited[nx][ny]) {
        q.push({nx, ny});
      }
    }
  }

  cout << "No" << endl;

  return 0;
}
