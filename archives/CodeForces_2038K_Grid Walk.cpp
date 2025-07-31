// INFO: Tags : -
//        URL : https://vjudge.net/problem/CodeForces-2038A
//
// 您有一个 n × n 网格和两个整数 a 和 b。行和列的编号都是从 1 到 n。我们把第 i 行和第 j 列的交点处的单元格记为 (i, j)。
// 您现在站在 (1, 1) 单元格，想要移动到 (n, n) 单元格。
// 假设您现在位于 (i, j) 单元格；如果存在相应的单元格，您可以一步移动到 (i, j+1) 单元格或 (i+1, j) 单元格。
// 我们将 (i, j) 单元格的成本定义为 c(i, j) = gcd(i, a) + gcd(j, b)。
// 从 (1, 1) 到 (n, n) 的路径成本是所访问单元格（包括起始单元格和终点单元格）的成本之和。
// 找出成本最小的路线并打印其成本。
//
// Input
// 唯一一行包含三个整数 n、a 和 b ( 2 ≤ n ≤ 10^6; 1 ≤ a, b ≤ 10^6 )。
//
// Output
// 打印一个整数 —— 从 (1, 1) 到 (n, n) 的最便宜路线的成本。
//
// HACK: Solution
// - Let P is some path from (1, 1) to (x, y).
// - ∑_((i,j)∈P) c(i, j) = ∑_((i,j)∈P) gcd(i, a) + gcd(j, b)
//                       ≥ x + y - 2 + ∑_(i=1)^x gcd(i, a) + ∑_(j=1)^y gcd(j, b)
// - If gcd(x, a) = 1 or gcd(y, b) = 1, then the lower bound is achieved
// - Let x be the maximum integer such that x ≤ n and gcd(x, a) = 1
// - Let y be the maximum integer such that y ≤ n and gcd(y, b) = 1
// - There exists a optimal path passing through (x, y)
// - The cost of the path (1, 1) -> (x, y) is already known
// - The cost of the path (x, y) -> (n, n) needs to be found
// - For n ≤ 10^6, we can prove that n - x ≤ 25 and n - y ≤ 25
// - dp[26][26]
// Time complexity: O(n log n)
//
// INFO: Memory : ~4200 kB
//         Time : ~250 ms

// Sample Input
// 2
// 4 2 4
// 10 210 420

// Sample Output
// 21
// 125

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;

  // HACK: 观察发现，无论我们如何操作，我们一定至少会加一遍所有的 gcd(i, a) 和 gcd(j, b)，
  //       于是我们单独考虑 gcd(i, a) 和 gcd(j, b)，他们的计算结果应该是有很多个位置是 1 的，
  //       对于第一列，gcd(1, b) 一定是 1，于是我们走第一列，
  //       为了拐弯后也成本最低，我们寻找一个最大的 x，使这一行的 gcd(x, a) = 1，
  //       于是我们在第一列一直走到 x 行，然后拐弯横着走，
  //       为了确保这样走是成本最小的，我们最多只能走到 y 列，这一列同理，是最大的 gcd(y, b) = 1；
  //       （当然，对于上面的走法，我们其实只需要确保每次拐的时候 gcd(x, a) 或 gcd(y, b) 是 1 即可）
  //       （但只拐一次显然更容易理解）
  //       对于剩下的部分，直接 dp 即可，可以证明不会超过 dp[26][26]。

  int x = 1;
  vector<int> gcda(n + 1);
  for (int i = 1; i <= n; i++) {
    gcda[i] = __gcd(i, a);
    if (gcda[i] == 1)
      x = i;
  }

  int y = 1;
  vector<int> gcdb(n + 1);
  for (int i = 1; i <= n; i++) {
    gcdb[i] = __gcd(i, b);
    if (gcdb[i] == 1)
      y = i;
  }

  // NOTE: 这相当于
  //       int ans = 0;
  //       for (int i = 1; i <= x; i++) {
  //         ans += gcda[i] + gcdb[1];
  //       }
  //       for (int i = 1; i <= y; i++) {
  //         ans += gcda[x] + gcdb[i];
  //       }
  //       ans -= gcda[x] + gcdb[1];
  int ans = x + y - 2;
  for (int i = 1; i <= x; i++) {
    ans += gcda[i];
  }
  for (int i = 1; i <= y; i++) {
    ans += gcdb[i];
  }

  int rn = n - x;
  int rm = n - y;

  vector<vector<int>> dp(rn + 1, vector<int>(rm + 1));
  dp[0][0] = ans;

  for (int i = 1; i <= rn; i++) {
    dp[i][0] = dp[i - 1][0] + gcda[x + i] + gcdb[1];
  }
  for (int j = 1; j <= rm; j++) {
    dp[0][j] = dp[0][j - 1] + gcda[1] + gcdb[y + j];
  }
  for (int i = 1; i <= rn; i++) {
    for (int j = 1; j <= rm; j++) {
      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + gcda[x + i] + gcdb[y + j];
    }
  }

  cout << dp[rn][rm] << "\n";
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
