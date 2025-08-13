// INFO: Tags : BFS
//        URL : https://vjudge.net/problem/QOJ-12372
//
// 题目描述
// 在一个 n × m 的 01 网格中，其中第 i 行第 j 列的元素为 a_(i,j)，
// 若 a_(i,j) = 1 则表示这个位置为空地，反之若 a_(i,j) = 0 则表示这个位置上有障碍物。
// 现在小猫从 (1, 1) 出发，想要去 (n, m)。
// 若小猫当前在 (x, y) 则一次移动后可以到 (x−1, y)、(x+1, y)、(x, y−1)、(x, y+1)、(x−1, y−1)、(x+1, y−1)、(x−1, y+1)、(x+1, y+1) 的位置上，
// 注意不能移动到地图外，也不能走到障碍物上。即任意时候 1 ≤ x ≤ n, 1 ≤ y ≤ m, a_(x,y) = 1。
// 因为小猫使用了难以控制的滑板火箭，每一分钟都会移动 [l, r] 次。
// 现在需要你求出小猫最少需要几分钟才能成功抵达终点（必须要某一分钟的移动全部结束后小猫的位置在 (n,m) 才算成功抵达），
// 如果无论经过多久都不能成功抵达请输出 -1。
//
// 输入格式
// 第一行一个整数 T（1 ≤ T ≤ 1000），表示测试数据组数。
// 接下来对于每一组测试数据，第一行两个整数 n,m（2 ≤ n, m ≤ 1000），表示 01 网格的大小。
// 接下来一行包含两个整数 l,r（1 ≤ l ≤ r ≤ 10^9 ），表示在一分钟内移动次数的限制范围。
// 接下来 n 行，每行 m 个字符，表示网格的元素 a_(i,j) ，字符仅会出现 0 或 1，且 a_(1,1) 与 a_(n,m) 一定为 1。
// 保证所有测试数据的 n × m 的和不超过 10^6。
//
// 输出格式
// 对于每一组测试数据输出一行，如果小猫能在有限时间内抵达 (n, m)，那么输出最少需要的分钟数，否则输出 -1。
//
// HACK: 题解
// 次题可以往回走非常重要，详细分析见注释
//
// INFO: Memory : ~13.7 MB
//         Time : ~50 ms

// Sample Input
// 3
// 5 5
// 2 3
// 10000
// 01000
// 00110
// 11001
// 11111
// 7 8
// 3 3
// 10101000
// 01010100
// 10000100
// 01000010
// 00100100
// 00011010
// 00000001
// 7 8
// 4 4
// 10101000
// 01010100
// 10000100
// 01000010
// 00100100
// 00011010
// 00000001

// Sample Output
// 2
// 3
// 3

#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 2147483647

using ull = unsigned long long;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void solve() {
  int n, m;
  cin >> n >> m;

  int l, r;
  cin >> l >> r;

  vector<string> g(n);
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }

  // NOTE: 以下 0 / 1 按走到这格时的步数分，0 为偶，1 为奇

  vector<vector<int>> dist0(n, vector<int>(m, INF));
  vector<vector<int>> dist1(n, vector<int>(m, INF));
  dist0[0][0] = 0;

  queue<array<int, 3>> q;
  q.push({0, 0, 0});

  // NOTE: BFS 最短路
  while (!q.empty()) {
    auto [x, y, f] = q.front();
    q.pop();

    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == '1') {
        if (f == 0 && dist1[nx][ny] == INF) {
          dist1[nx][ny] = dist0[x][y] + 1;
          q.push({nx, ny, 1});
        }

        else if (f == 1 && dist0[nx][ny] == INF) {
          dist0[nx][ny] = dist1[x][y] + 1;
          q.push({nx, ny, 0});
        }
      }
    }
  }

  ull d0 = dist0[n - 1][m - 1];
  ull d1 = dist1[n - 1][m - 1];

  // NOTE: 如果不管偶数步还是奇数步都走不到，直接返回 -1。
  if (d0 == INF && d1 == INF) {
    cout << -1 << endl;
    return;
  }

  // NOTE: 向上取整
  // HACK: 合理，因为多出来的步可以在最后两格反复横跳消耗掉。
  ull t0 = (d0 + r - 1) / r;
  ull t1 = (d1 + r - 1) / r;

  // HACK: 如果 l 和 r 不相等，可以证明，总是可以走到（记得反复横跳），
  //       此时取偶数步时间和奇数步时间最小值即可。
  if (l != r) {
    cout << min(t0, t1) << endl;
    return;
  }

  // HACK: 如果 r == l 且为偶数，无论走几次（指时间，下同），都只能走出偶数步
  //       所以如果偶数步可以走到就返回其时间，
  //       否则走不到，返回 -1。
  if (l % 2 == 0) {
    if (d0 == INF) {
      cout << -1 << endl;
    } else {
      cout << t0 << endl;
    }
  }

  // HACK: 如果 r == l 且为奇数，此时可以走出奇数步（走奇数次），也可以走出偶数步（走偶数次）。
  else {
    // HACK: 如果走偶数步能走到，但是走的次数是奇数，
    //       就把次数 +1（反复横跳即可）以确保走偶数步。
    if (d0 != INF) {
      if (t0 % 2 == 1)
        t0++;
    }
    // HACK: 同理
    if (d1 != INF) {
      if (t1 % 2 == 0)
        t1++;
    }
    cout << min(t0, t1) << endl;
  }
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
