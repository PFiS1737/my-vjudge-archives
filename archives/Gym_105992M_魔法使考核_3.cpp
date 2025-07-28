// NOTE: 上一个写法的优化，逆天直接统计二进制中 1 的个数
//
// INFO: Memory : -
//         Time : ~470 ms

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

void solve() {
  int n, x, y;
  cin >> n >> x >> y;

  vector<int> a(n);
  for (int &ai : a)
    cin >> ai;

  ull ans = numeric_limits<ull>::max();

  // NOTE: 枚举 y 操作的次数，由于 ai <= 1e9，显然 y 操作不会超过 30 次
  for (int cnty = 0; cnty <= 30; cnty++) {
    ull cntx = 0;

    for (int ai : a)
      cntx += __builtin_popcount(ai & ((1 << cnty) - 1)) + (ai >> cnty);
    // NOTE:  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    ^~~~~~~~~~
    //        统计 ai 的二进制中，低 cnty 位中 1 的个数     |
    //        你可以一位一位的考虑，对于每一位：            |
    //        如果是 1，会统计上，认为进行一次 x 操作，     |
    //        然后跳到下一位相当于除以了 2，                |
    //        所以这里相当于下面的代码：                    |
    //                                                      |
    //        while (x && cnty) {                           |
    //          if (x & 1) {      // x % 2 == 1             |
    //            // x ^= 1;      // x--                    |
    //            cntx++;                                   |
    //          }                                           |
    //          if (cnty) {                                 |
    //            x >>= 1;        // x /= 2                 |
    //            cnty--;                                   |
    //          }                                           |
    //        }                                             |
    //                                                      之前进行了 cnty 次 y 操作，已经没有额外的 y 操作可以用了
    //                                                      剩下的数就只能通过多次 x 操作，一个一个减掉

    if (cntx * x + cnty * y < ans)
      ans = cntx * x + cnty * y;
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
