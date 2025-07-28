// // INFO: Tags : 构造
// //        URL : https://vjudge.net/problem/Gym-105992G
// //
// // Description
// 给定一个正整数 n，你需要构造一个 n × n 的矩阵。
// 矩阵的第 i 行第 j 个元素，记作 A_(i,j)。
// 你的目标是使得：对于所有 1 ≤ i ≤ n 且 1 ≤ j ≤ n，都有
// - 如果 i>1，有 gcd(A_(i,j), A_(i−1,j)) = 1。
// - 如果 j>1，有 gcd(A_(i,j), A_(i,j−1)) = 1。
// 并且所有的数字都满足 1 ≤ A_(i,j) ≤ n^2+40n，且所有数字互不相同。
// 也就是说，矩阵中，所有的数字与它上下左右相邻的四个数字都互质，
// 并且矩阵中的数都不超过 n^2+40n。
//
// Input
// 一行一个正整数 n ( 1 ≤ n ≤ 2500 )。
//
// Output
// 输出 n 行，每行 n 个正整数，用空格分隔。
// 如果有多种满足条件的解，输出任意合法解即可。
//
// HACK: Solution
// 考虑求出第一个大于 n 的质数 P，经过暴力检验发现 P < n + 40 ( n <= 2500 )。
// 然后按照如下规则构造即可
// 1         2         3         ⋯  n
// 1+P       2+P       3+P       ⋯  n+P
// 1+2P      2+2P      3+2P      ⋯  n+2P
// ⋮         ⋮         ⋮         ⋱  ⋮
// 1+(n−1)P  2+(n−1)P  3+(n−1)P  ⋯  n+(n−1)P
//
// INFO: Memory : -
//         Time : ~890 ms

// Sample Input
// 2
// 2
// 3

// Sample Output
// 1 3
// 5 4
// 1 5 9
// 4 7 8
// 3 2 11
//
// # FIXME: 这题需要 Special Judge
// #        普遍的答案应该是这个：
// #        1 2
// #        4 5
// #        1 2 3
// #        6 7 8
// #        11 12 13

#include <iostream>
using namespace std;

inline bool is_prime(int x) {
  if (x == 1)
    return false;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0)
      return false;
  return true;
}

void solve() {
  int n;
  cin >> n;

  int p;
  for (int i = n + 1;; i++) {
    if (is_prime(i)) {
      p = i;
      break;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << j + i * p << " \n"[j == n];
    }
  }
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
