// INFO: Tags : -
//        URL : https://vjudge.net/problem/Gym-105442F
//
// INFO: Memory : ~400 kB
//         Time : ~220 ms

// Sample Input
// 2
// 2 2
// 1 2
// 3 4
// 3 4
// 2 2 4 0
// 1 3 1 0
// 2 5 3 1

// Sample Output
// 8
// 24

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  int ans = 0;

  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      ans += a[i][j];
    }
  }

  // NOTE: 长宽有一个是奇数就一定能走满
  if ((n % 2) || (m % 2)) {
    cout << ans << '\n';
    return;
  }

  // NOTE: 都是偶数的话，可以证明，总是存在一条线路不经过有一个坐标是奇数的格子
  //       于是找到上面数字最小的这样的格子，然后减去即可
  int min = numeric_limits<int>::max();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2) {
        min = std::min(min, a[i][j]);
      }
    }
  }

  cout << ans - min << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL_JUDGE
  int T;
  cin >> T;
  while (T--)
#endif
    solve();
  return 0;
}
