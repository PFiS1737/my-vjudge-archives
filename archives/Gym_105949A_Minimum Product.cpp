// INFO: Tags : 最短路
//        URL : https://vjudge.net/problem/Gym-105949A
//
// 每条边有属性 (ai, bi)，定义路径 P 权值为：(∑_(i∈P) ai) * (∑_(i∈P) bi)
// 求节点 1 到节点 N 的所有可能路径中，最小的权值是多少。
// N ≤ 300, M ≤ 1000, 1 ≤ ai, bi ≤ 200。
//
// HACK: 官方题解
// （另一种 Dijkstra 解法看代码注释，虽然好像是错误解法，但确实 A 了）
// 不难想到设计 DP 状态 f_(sum,u) 表示目前到达 u 节点且 ∑ai = sum 时，∑bi 的最小值。
// 注意到 ai > 0，sum 相同的状态之间没有转移。
// 所以可以直接枚举 sum 再枚举可行的边，直接转移。
// 时间复杂度 O(N*M*max{ai})。
//
// INFO: Memory : -
//         Time : <100 ms

// Sample Input
// 1
// 5 9
// 3 4 3 5
// 4 5 5 1
// 1 4 2 2
// 3 4 5 2
// 1 4 2 4
// 2 1 3 2
// 4 2 5 4
// 4 1 2 2
// 4 1 3 1

// Sample Output
// 7 3

#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

using ull = unsigned long long;

void solve() {
  int n, m;
  cin >> n >> m;

  using E = tuple<int, int, int>; // (v, a, b)
  vector<vector<E>> G(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, a, b;
    cin >> u >> v >> a >> b;
    G[u].emplace_back(v, a, b);
  }

  // NOTE: 多因素 Dijkstra
  //       dist 中记录多组 (suma, sumb)，
  //       而不是只记录最小的 suma * sumb。
  vector<map<int, int>> dist(n + 1); // dist[u] = { [suma] = sumb }
  dist[1][0] = 0;

  using S = tuple<ull, int, int, int>; // (suma * sumb, suma, sumb, u)
  priority_queue<S, vector<S>, greater<S>> pq;
  pq.push({0, 0, 0, 1});

  ull minp = numeric_limits<ull>::max();
  int mina = -1, minb = -1;

  while (pq.size()) {
    auto [p, suma, sumb, u] = pq.top();
    pq.pop();

    // HACK: 本题最重要的减枝
    if (p >= minp)
      continue;

    // NOTE: 每次跑到目标点，且路径权值更小，就记录。
    if (u == n && p < minp) {
      minp = p;
      mina = suma;
      minb = sumb;
      continue;
    }

    for (auto &[v, a, b] : G[u]) {
      int na = suma + a;
      int nb = sumb + b;
      ull np = (ull)na * nb;

      // NOTE: 如果有任何已有记录比当前想要插入的小，就不插了，
      //       这里如果数据很大，会爆，但本题可以。
      //       这里用 map 主要是想要使用它的有序性，让这里从最小的开始比，
      //       但有可能是负优化。
      for (auto &[a2, b2] : dist[v]) {
        if (a2 <= na && b2 <= nb) {
          goto end;
        }
      }

      // FIXME: 不能 clear()，太慢了，直接给干 T 了。
      // dist[v].clear();
      dist[v][na] = nb;
      pq.push({np, na, nb, v});

    end: {}
    }
  }

  cout << mina << " " << minb << '\n';
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
