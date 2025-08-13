// INFO: Tags : -
//        URL : https://vjudge.net/problem/Gym-103729B
//
// 有一个容量仅在一半位置有刻度的量杯，有两类水，求最小接水步数使得
// 杯子里面两类水的比例为 x : y，或者输出无解。
//
// HACK: 官方题解
// 假设当前第一类水的比例为 d，那么一次接水后其比例变为 d/2 或 (d+1)/2，
// 初始时 d = 0 或 1。
// 分析一下可以发现，如果把 d 化为最简分数，那么分子总是奇数，分母总是 2^n，
// 且 n + 1 是总接水次数，其他的打表找规律同样可以得到相同结论。
// 对 x 与 y 约分后判断它们是否为奇数且它们的和是否为 2 的次幂即可。
// 关于约分正确性的证明见 hard version。
//
// INFO: Memory : -
//         Time : ~210 ms

// Sample Input
// 4
// 3 5 1 1
// 2 6 1 1
// 5 7 1 1
// 0 10 1 1

// Sample Output
// 4
// 3
// -1
// 1

#include <iostream>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
  // return __gcd(a, b);
  while (b) {
    ll t = a % b;
    a = b;
    b = t;
  }
  return a;
}

void solve() {
  ll x, y, a, b;
  cin >> x >> y >> a >> b;

  // NOTE: 约分
  ll g = gcd(x, y);
  x /= g;
  y /= g;

  // NOTE: 如果是 2 的整数次幂，则幂次 +1 即为所求
  ll t = x + y;
  for (int i = 0; i < 64; i++) {
    if (t == 1ll << i) {
      cout << i + 1 << "\n";
      return;
    }
  }

  cout << "-1\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
