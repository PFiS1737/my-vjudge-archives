// INFO: Tags : -
//        URL : https://vjudge.net/problem/Gym-105930G
//
// Description
// 一条装配线上有 k 名工人，编号从 1 到 k，每名工人都有一个收件箱。工人们将要加工 n 个工件，
// 第 i个工件将在第 t_i 分钟的开头加入到第 w_i 名工人的收件箱。
// 每分钟内，以下事件将按顺序发生：
// 1. 新工件（如果有的话）被加入到一些工人的收件箱里。
// 2. 如果一名工人的收件箱不是空的，他/她会从收件箱里拿起一个工件并加工。每名工人的该事件同时发生。
// 3. 如果一名工人刚刚加工了工件：
// • 对于工人 1 ≤ i < k，他/她会将该工件放入工人 (i + 1) 的收件箱。
// • 对于工人 k，他/她会将该工件放入出货箱，该工件加工完成。
// 每名工人的该事件也是同时发生的。
// 求完成所有 n 个工件的加工需要几分钟。
//
// Input
// 有多组测试数据。第一行输入一个整数 T（1 ≤ T ≤ 104）表示测试数据组数，对于每组测试数据：
// 第一行输入两个整数 n 和 k（1 ≤ n ≤ 2 × 105，1 ≤ k ≤ 109），表示工件的数量以及工人的数量。
// 对于接下来 n 行，第 i 行输入两个整数 w_i 和 t_i（1 ≤ w_i ≤ k，1 ≤ t_i ≤ 10^9），
// 表示第 i 个工件将在第 t_i 分钟的开头加入到第 w_i 名工人的收件箱。
// 保证所有数据 n 之和不超过 2 × 10^5。
//
// Output
// 每组数据输出一行一个整数，表示完成所有 n 个工件的加工需要几分钟。
//
// HACK: Solution
// 工件 i 原本的结束时间是 (t_i + k − w_i)，但每个时间点只能完成一个工件。
// 因此设 a_i 表示从小到大排序后的工件完成时间，
// 依次进行更新 a_i ← max(a_i, a_(i−1) + 1) 即可。
// 复杂度 O(n log n)。
//
// INFO: Memory : -
//         Time : ~600 ms

// Sample Input
// 2
// 4 3
// 3 2
// 2 1
// 3 2
// 1 2
// 2 10
// 1 7
// 4 20

// Sample Output
// 5
// 26

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      long long w, t;
      cin >> w >> t;
      a[i] = t + (k - w);
    }
    sort(a.begin(), a.end());
    for (int i = 2; i <= n; i++) {
      a[i] = max(a[i], a[i - 1] + 1); // NOTE: 多数情况下应该是后者大
    }
    cout << a[n] << endl;
  }
  return 0;
}
