// NOTE: 另一个做法，好像看懂怎么写的了，相较上一个做法略显暴力 :)
//       他这个方法放下一个里面一起讲
//
// INFO: Memory : -
//         Time : ~1100 ms

// Sample Input
// 2
// 6 1 1
// 1 1 4 5 1 4
// 5 2 5
// 10 7 9 0 3

// Sample Output
// 9
// 32

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

using ull = unsigned long long;

ull cntX(int x, int cnty) {
  ull cntx = 0;
  while (x && cnty) {
    if (x & 1) { // x % 2 == 1
      x ^= 1;    // x--
      cntx++;
    }
    if (cnty) {
      x >>= 1; // x /= 2
      cnty--;
    }
  }
  return cntx + x;
}

void solve() {
  ull n, x, y;
  cin >> n >> x >> y;

  vector<int> a(n);
  for (int &ai : a)
    cin >> ai;

  ull ans = numeric_limits<ull>::max();

  for (int cnty = 0; cnty <= 30; cnty++) {
    ull cntx = 0;

    for (int ai : a)
      cntx += cntX(ai, cnty);

    if (cntx * x + y * cnty < ans)
      ans = cntx * x + y * cnty;
  }

  cout << ans << '\n';
}

int main() {
#ifdef LOCAL_JUDGE
  int T;
  cin >> T;
  while (T--)
#endif
    solve();
  return 0;
}
