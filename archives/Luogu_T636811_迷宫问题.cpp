// INFO: Tags: DFS
//
// 题目描述
// 给定一个 n 行 m 列的迷宫，迷宫内 '.' 表示当前位置是空地，'#' 表示当前位置是墙。
// 每次可以朝上下左右四个方向移动，不可以走到墙上或者迷宫外。
// 求从 (1, 1) 出发可以到达的格子数。
//
// 输入格式
// 第一行包含两个整数 n、m。
// 接下来 n 行表示迷宫，每行有 m 个字符。
//
// 输出格式
// 输出一个整数。
//
// 说明/提示
// 对于 100% 的数据，1 ≤ n、m ≤ 100。

// Sample Input
// 3 3
// ...
// ..#
// .#.

// Sample Output
// 6

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

  int cnt = 0;

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
    cnt++;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && mas[nx][ny] && !visited[nx][ny]) {
        q.push({nx, ny});
      }
    }
  }

  cout << cnt << endl;

  return 0;
}
