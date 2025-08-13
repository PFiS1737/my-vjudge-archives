// INFO: Tags : -
//        URL : https://vjudge.net/problem/Gym-105949H
//
// T 组数据，从点 (x, y) 可以走到 (x±1, y±1), (x±1, y±2), (x±2, y±1), (x±2, y±2)，
// 问走到 (X, Y) 的最小步数。
// T ≤ 10^6 , |x|, |y|, |X|, |Y| ≤ 10^9 。
//
// HACK: 官方题解
// （更好理解的方法，看我下面写注释里的）
// 两维可以拆开来独立考虑。
// 会发现如果可以 c 步从 x 走到 X，那么 c+2, c+4, ... 都可以（可以来回浪费 2 步）。
// 因此答案为：min(max(f(x−X), f(y−Y)), max(f(x−X), f(y−Y)))
// 其中 f_(1/0)(x) 表示走奇/偶步从 0 到 x 的最少操作次数。
// 会发现大部分：f1(x) = ⌊x/2⌋+even(⌊x/2⌋)
//               f0(x) = ⌊x/2⌋+odd(⌊x/2⌋)
// 只有 f(0) = 3 是个例，注意特判。
//
// INFO: Memory : -
//         Time : ~1800 ms

// Sample Input
// 5
// 1 2 1 2
// 1 1 3 4
// -2 -2 -100 15
// 1 1 98 98
// -1 -1 98 98

// Sample Output
// 0
// 2
// 49
// 49
// 50

#include <iostream>
using namespace std;

void solve() {
  int x, y, X, Y;
  cin >> x >> y >> X >> Y;

  int dx = abs(X - x);
  int dy = abs(Y - y);

  // NOTE: 确保 dy >= dx。
  if (dx > dy)
    swap(dx, dy);

  // NOTE: 向上取整，得到两个方向最少步数，
  //       注意原 dy, dx 有新的含义，为最多步数。
  int tx = (dx + 1) / 2;
  int ty = (dy + 1) / 2;

  // NOTE: 注意上面确保了 dy >= dx，
  //       如果两个区间 [tx, dx], [ty, dy] 有交集，
  //       说明走到更远的 Y 所用的步数，经过合理的分配，一定也可以走到 X。
  if (tx <= ty && ty <= dx) {
    cout << ty << endl;
    return;
  }

  // NOTE: 否则，即 dx < ty，
  //       说明走到 Y 的步数，就算以最慢的方式（一步一格），也会走过 X，
  //       但考虑到我们可以来回走来浪费步数，最后结果还是 ty，
  //       但如果 ty - dx == 1，即步数只差 1，就回不来了，所以要加一步。
  //       （差 3 没事，你可以往回一步两格，然后再两步一格回来，其他奇数步同理）
  int dd = ty - dx;
  if (dd == 1)
    cout << ty + 1 << endl;
  else
    cout << ty << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
