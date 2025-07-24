// INFO: Tags : 差分数组 区间递增
//        URL : https://vjudge.net/problem/Gym-105930D
//
// Description
// 某分布式系统有 n 个编号从 0 到 (n − 1) 的工作节点。
// 该系统将处理 q 项任务，其中第 i 项任务可以记为两个整数 a_i 与 b_i，
// 表示该任务有 a_i 项编号从 0 到 (a_i − 1) 的子任务，
// 且子任务 j 会分配给工作节点 (b_i + j) mod n。
// 对于每个 0 ≤ k < n，求所有任务处理完成后，工作节点 k 一共被分配了几项子任务。
//
// Input
// 有多组测试数据。第一行输入一个整数 T（1 ≤ T ≤ 10^4）表示测试数据组数，对于每组测试数据：
// 第一行输入两个整数 n 和 q（1 ≤ n, q ≤ 2 × 10^5），表示工作节点的数量以及任务的数量。
// 对于接下来 q 行，第 i 行输入两个整数 a_i 和 b_i（1 ≤ a_i ≤ 10^9，0 ≤ b_i < n），表示第 i 项任务。
// 保证所有数据 n 之和与 q 之和均不超过 2 × 10^5。
//
// Output
// 每组数据输出一行 n 个由单个空格分隔的整数 v_0, v_1, ... , v_(n−1)，其中 v_k 表示所有任务处理完成后，
// 工作节点 k 一共被分配了几项子任务。
//
// HACK: Solution
// 对于每个子任务，所有节点至少分配 ⌊a_i/n⌋ 个子任务，
// 剩下的 a_i mod n 个子任务从节点 b_i 开始，连续分配给接下来的节点。
// 连续分配任务，也就是某个区间的答案加 1。
// 因为只在最后输出答案，可以用差分数组维护。
// 复杂度 O(n + q)。
//
// INFO: Memory : -
//         Time : ~500 ms

// Sample Input
// 2
// 7 3
// 10 0
// 4 2
// 21 1
// 1 2
// 200 0
// 100 0

// Sample Output
// 5 5 6 5 5 5 4
// 300

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;

    // NOTE: 使用差分数组进行区间递增，注意区间为左闭右开 [a, b)
    //       方法是：区间开头 diff[a] += 要加的值，区间末尾 diff[b] -= 对应的值
    //       特别的：对于区间 [a, n)，只需在 diff[a] 上增加要增加的值即可，因为 diff[n] 用不到
    vector<long long> diff(n, 0);

    for (int i = 0; i < q; i++) {
      int a, b;
      cin >> a >> b;

      // 一共有完整的 a / n 趟
      diff[0] += a / n;

      if (!(a % n))
        continue;

      // 剩下的 a % n 个从 b 开始递增
      int l = b;
      int r = (b + (a % n)) % n;
      if (l < r) {
        // 没有跨越 n
        diff[l] += 1;
        diff[r] -= 1;
      } else {
        // 跨越了末尾：分两段 [l, n), [0, r)
        diff[l] += 1;
        diff[0] += 1;
        diff[r] -= 1;
      }
    }

    // 还原差分数组为原数组并输出
    vector<long long> w(n, 0);
    w[0] = diff[0];
    cout << w[0];
    for (int i = 1; i < n; i++) {
      w[i] = w[i - 1] + diff[i]; // NOTE: 注意还原方法，有助于理解差分数组
      cout << " " << w[i];
    }
    cout << "\n";
  }
  return 0;
}
