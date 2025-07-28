// INFO: Tags : -
//        URL : https://vjudge.net/problem/Gym-105992M
//
// Description
// 见习魔法少女 Chiaro 正在参加魔法使考试，大魔法使 Shiro 在她面前放置了 n 个没有任何魔力值的魔法球，
// Chiaro 需要施加若干次魔法，让这些魔力球各装满指定大小的魔力值。
// 具体来说，初始时这些魔法球的魔力值都是 0，Chiaro 要在施加若干次魔法后使得第 i 个魔法球最终有 ai 的魔力值。
// 然而 Chiaro 作为见习魔法少女掌握的魔力知识很少，她只会两种魔法，而且每种魔法都会消耗一定的体力：
// - 将任意一个魔法球增加 1 的魔力值，这会消耗她 x 点体力。
// - 选择任意区间 [l,r]，将第 l 个到第 r 个共 r − l + 1 个魔法球的魔力值翻倍，这会消耗她 y 点体力。
// 很显然，Chiaro 一定可以只用上述两种魔法若干次来完成这项测试。
// 不过这场魔法使考试才刚刚开始，后面还有很多更困难的测试项目，所以 Chiaro 想用尽可能少的体力完成这个测试，
// 请你帮她算出最少用多少体力可以完成这个测试。
//
// Input
// 第一行三个非负整数 n, x, y ( 1 ≤ n ≤ 3×10^5, 0 ≤ x, y ≤ 10^7 )。
// 接下来一行 n 个非负整数表示序列 a1 ,a2 , ..., an ( 0 ≤ ai ≤ 10^9 )。
//
// Output
// 一行一个整数，表示消耗的最少体力值。
//
// HACK: Solution
// 可以注意到翻倍操作的区间性是没用的，代价最低的做法一定是合理安排加一和翻倍操作的顺序，使得翻倍操作都是全局翻倍
// __考虑只有加一操作和全局翻倍时：__
// __• 如果翻倍的代价低于加一的代价，那么一定是从高到低枚举每一位，把这一位是 1 的数字都加一，全部加完之后再翻倍，这样重复操作__
// __• 如果翻倍代价更高，那么有可能的代价更低的方案是，先把高若干位都只用加一操作加出来，然后再开始加一、翻倍、加一、翻倍的循环，直接枚举两种操作的分界位即可__
// 时间复杂度：O(n log max(ai))
// 将思考方向从充满魔法球转变为清空魔法球，解题方法见下面注释
//
// INFO: Memory : -
//         Time : ~550 ms

// Sample Input
// 2
// 6 1 1
// 1 1 4 5 1 4
// 5 2 5
// 10 7 9 0 3

// Sample Output
// 9
// 32

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ull = unsigned long long;

void solve() {
  ull n, x, y;
  cin >> n >> x >> y;

  vector<int> a(n);
  for (int &ai : a)
    cin >> ai;

  ull ans = 0;

  // HACK: 考虑把操作方向从 0 -> ai，变成 ai -> 0
  // NOTE: 这里也可以直接循环 30 遍，
  //       因为 ai <= 1e9，显然除 2 操作不会超过 30 次
  while (any_of(a.begin(), a.end(), [](int i) { return i > 0; })) {
    ull cntx = 0;

    // NOTE: 每次循环（是说外层的 while 循环）进行两次操作
    for (int &ai : a) {

      // NOTE: 第一次总是把奇数减 1，变为偶数，这会产生一次 x 操作
      if (ai % 2 == 1) {
        ai--;
        ans += x;
      }

      // NOTE: 第二次是把所有数除 2，该操作不确实是多次 x 还是一次 y
      ai /= 2;

      // NOTE: 记录一下除 2 会进行多少个 x 操作
      cntx += ai;
    };

    // NOTE: 如果除 2 的操作使用多次 x 操作更划算，就进行多次 x，否则进行一次 y
    ans += min(cntx * x, y);
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
