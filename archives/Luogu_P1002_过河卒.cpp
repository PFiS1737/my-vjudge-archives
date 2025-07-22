// INFO: Tags: DP
//
// 题目描述
// 棋盘上 A 点有一个过河卒，需要走到目标 B 点。卒行走的规则：可以向下、或者向右。
// 同时在棋盘上 C 点有一个对方的马，该马所在的点和所有跳跃一步可达的点称为对方马的控制点。因此称之为“马拦过河卒”。
// 棋盘用坐标表示，A 点 (0, 0)、B 点 (n, m)，同样马的位置坐标是需要给出的。
// ![](https://cdn.luogu.com.cn/upload/image_hosting/ipmwl52i.png)
// 现在要求你计算出卒从 A 点能够到达 B 点的路径的条数，假设马的位置是固定不动的，并不是卒走一步马走一步。
//
// 输入格式
// 一行四个正整数，分别表示 $B$ 点坐标和马的坐标。
//
// 输出格式
// 一个整数，表示所有的路径条数。
//
// 说明/提示
// 对于 100% 的数据，1 ≤ n,m ≤ 20，0 ≤ 马的坐标 ≤ 20。

// Sample Input
// 6 6 3 3

// Sample Output
// 6

#include <iostream>
#include <vector>
using namespace std;

int dx[] = {0, 2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};

int main() {
  int Bx, By, Cx, Cy;
  cin >> Bx >> By >> Cx >> Cy;

  vector<vector<bool>> st(Bx + 1, vector<bool>(By + 1, false));
  for (int i = 0; i < 9; i++) {
    int nx = Cx + dx[i];
    int ny = Cy + dy[i];
    if (nx >= 0 && nx <= Bx && ny >= 0 && ny <= By) {
      st[nx][ny] = true;
    }
  }

  vector<vector<long long>> dp(Bx + 1, vector<long long>(By + 1, 0));
  dp[0][0] = 1;

  for (int x = 0; x <= Bx; x++) {
    for (int y = 0; y <= By; y++) {
      if (st[x][y])
        continue;
      if (x > 0)
        dp[x][y] += dp[x - 1][y];
      if (y > 0)
        dp[x][y] += dp[x][y - 1];
    }
  }

  cout << dp[Bx][By] << endl;

  return 0;
}
