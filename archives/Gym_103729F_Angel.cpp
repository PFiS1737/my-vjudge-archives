// INFO: Tags : -
//        URL : https://vjudge.net/problem/Gym-103729F
//
// 一排有 n 个洞，有一只兔子在某个洞，每个时刻必定移动到相邻的洞中，
// 需要构造长度最短的询问序列 qi，第 i 项表示询问在兔子第 i 次移动前是否在 qi 这个洞中，
// 使得至少猜中一次。
//
// HACK: 官方题解
// 考虑兔子发生移动时奇偶性必定发生改变，那么可以钦定兔子初始奇偶性。
// 确定了奇偶性后，由于兔子一次只能走一步，所以可以把它往一边赶。
// 最坏情况下重复两遍这个过程即可，对边界稍加讨论可以发现 2 * (n − 2) 大概就是这个思路下的最小值（证明见题解），
// 注意特判 n = 1, 2 的情况。
//
// INFO: Memory : -
//         Time : ~60 ms

// Sample Input
// 3

// Sample Output
// 2
// 2 2 

#include <iostream>
using namespace std;

void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1\n1 ";
  } else if (n == 2) {
    cout << "2\n2 2 ";
  } else {
    cout << 2 * (n - 2) << '\n';
    for (int i = 2; i <= n - 1; i++) {
      cout << i << " ";
    }
    for (int i = n - 1; i >= 2; i--) {
      cout << i << " ";
    }
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  // cin >> T;
  while (T--)
    solve();
  return 0;
}
