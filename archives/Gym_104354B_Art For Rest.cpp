// INFO: Tags : -
//        URL : https://vjudge.net/problem/Gym-104354B
//
// 给定一个长度为 n 的非负整数序列 a1, a2, ..., an，记作 A。
// 对于正整数 k，按照以下方式得到序列 A′_k ：
// • 将 A 划分为 ⌈n/k⌉ 段，第 i 段为 a_(k(i−1)+1), a_(k(i−1)+2), ..., a_min{k_i,n}
// • 每一段升序排序后依次连接得到 A′_k
// 试求有多少个 k 满足 1 ≤ k ≤ n，且对于任意 1 ≤ i < j ≤ n 有 A′_(k,i) ≤ A′_(k,j)。
//
// 输入格式
// 第一行包含一个正整数 n（1 ≤ n ≤ 10^6），表示非负整数序列 A 的长度。
// 第二行包含 n 个非负整数 a1, . . . , an（0 ≤ ai ≤ 10^9），表示给定的序列 A。
//
// 输出格式
// 一行包含一个整数，表示答案。
//
// HACK: 官方题解
// 记 premax_i = max_(1≤j≤i){ai}, ufmin_i = min_(i≤j≤n){ai}
// 对于 1 ≤ k ≤ n，A′_k 单调不减等价于
// premax_(ik) ≤ sufmin_(ik+1) 对所有 1 ≤ i < ⌈n/k⌉ 成立，
// 直接判断即可。
// 复杂度 O(n log n)
//
// NOTE: 题解里这个“等价于”我是真没想明白怎么等价出来的 :(
//
// INFO: Memory : 12 MB
//         Time : ~300 ms

// Sample Input
// 3
// 13
// 1 1 4 5 1 4 1 9 1 9 8 1 0
// 4
// 114 514 1919 810
// 6
// 121 117 114 105 107 111

// Sample Output
// 1
// 2
// 1

#include <climits>
#include <iostream>
using namespace std;

#define N 1000005
int n, a[N], b[N], c[N];

bool check(int k) {
  for (int i = k; i <= n; i += k)
    if (b[i] > c[i + 1])
      return false;
  return true;
};

void solve() {
  cin >> n;

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  // NOTE: 前缀最大值
  b[0] = INT_MIN;
  for (int i = 1; i <= n; i++)
    b[i] = max(b[i - 1], a[i]);

  // NOTE: 后缀最小值
  c[n + 1] = INT_MAX;
  for (int i = n; i >= 1; i--)
    c[i] = min(c[i + 1], a[i]);

  int cnt = 0;
  for (int k = 1; k <= n; k++)
    if (check(k))
      cnt++;

  cout << cnt << "\n";
}

int main() {
  // FIXME: 不加会 TLE
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
