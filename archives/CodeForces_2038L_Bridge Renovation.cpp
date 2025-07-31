// INFO: Tags : -
//        URL : https://vjudge.net/problem/CodeForces-2038L
//
// 三座桥的长度相同，但宽度不同。它们的宽度分别为 18、21 和 25 个单位。在公园翻新过程中，Monocarp 必须用新木板替换作为桥面的旧木板。
// 木板的标准长度为 60 个单位。Monocarp 已经知道每座桥需要 n 块木板。
// 但由于桥的宽度不同，第一座桥需要长度为 18 的 n 块木板，第二座桥需要长度为 21 的 n 块木板，最后一座桥需要长度为 25 的 n 块木板。
// 负责翻修的工人可以将木板切割成若干部分，但拒绝将木板连接起来，因为这样会产生薄弱点，而且看起来很难看。
// Monocarp 想买尽可能少的木板，但却苦于计算不出所需木板的数量。您能帮助他吗？
//
// Input
// 第一行也是唯一一行包含一个整数 n ( 1 ≤ n ≤ 1000 ) —— 三座桥所需的木板数量。
//
// Output
// 打印一个整数 —— 如果木板可以切割成若干部分，则 Monocarp 覆盖所有三座桥所需的最小标准长度木板数量（60 单位）。
//
// HACK: Solution
// 以下官方题解，另一种思路见代码注释
// - Greedy ideas
// - Creating pairs 25 + 25 is profitable
// - Need ⌊n/2⌋ pairs of 25 + 25
// - Creating pairs 21 + 21 + 18 is profitable
// - Need ⌊n/2⌋ pairs of 21 + 21 + 18
// - Additionally, need (n%2) pairs of 25 + 21
// - For boards 25 and 21, exactly n planks of 60 are needed
// - There are ⌈n/2⌉ planks of 18 left
// - Creating pairs 18 + 18 + 18 is profitable
// - Need ⌈⌈n/2⌉/3⌉ = ⌈n/6⌉ pairs of 18 + 18 + 18
// Answer to the problem: n + ⌈n/6⌉
//
// INFO: Memeory : ~100 kB
//         Time : ~60 ms

// Sample Input
// 3
// 1
// 3
// 1000

// Sample Output
// 2
// 4
// 1167

#include <iostream>
using namespace std;

void solve() {
  int n;
  cin >> n;

  // NOTE: 考虑到 18 和 21 的木板可以三个放在一起切，
  //       我们将其一起考虑，即一共需要 2n 块，而每块大木板上可以切下 3 块，
  //       于是需要 2n/3 块大木板。
  int ans = 2 * n / 3;

  // NOTE: 经过上面的操作，可能还有一些 18 和 21 没有被切下来，
  //       于是将它们和 25 一起考虑。
  int r = 2 * n % 3;

  // NOTE: 此时，一块大木板上只能切下 2 块，
  //       于是需要 (r+n+1)/2 块大木板，
  //       此处 +1 表示向上取整，为了确保切完，
  //       而不会剩下些 25 的（或是其他什么？）。
  ans += (r + n + 1) / 2;

  cout << ans << endl;
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
