// INFO: Tags : 并查集
//        URL : https://vjudge.net/problem/Gym-105992D
//
// Description
// Djangle 给你一个连通的简单无向图，初始时每条边都有一个颜色：白色或黑色。
// 每次操作，你可以选择一个包含至少一条白边的简单环，将这个环中所有的边都涂成黑色。
// 请注意，你并不一定需要最终把所有边都变为黑色。
// 请问，最多可以进行多少次这样的操作？
// 简单环的定义是：由若干条边首尾连接而成的闭合路径，且其中没有重复的边。
//
// Input
// 第一行包含一个整数 T ( 1 ≤ T ≤ 10^4 )，表示数据组数。
// 接下来每组数据的第一行包含两个整数 n, m ( 1 ≤ n ≤ ∑n ≤ 2×10^5, n−1 ≤ m ≤ min{3×10^5, n(n−1)/2}, ∑m ≤ 3×10^5 )，表示图的点数和边数。
// 接下来 m 行，每行包含三个整数 u, v, col ( 1 ≤ u, v ≤ n, col ∈ { 0,1 } )，
// 表示存在一条连接点 u 和点 v 的无向边，颜色为 col。如果 col=0，表示该边为白色；否则表示该边为黑色。
// 保证输入的图没有重边和自环。
//
// Output
// 对于每组数据，输出一个整数，表示最多可以进行多少次操作。
//
// HACK: Solution
// 把操作看成两种情况：
// • 把一个任意白边变黑，贡献 +0
// • 把一个两端被黑边连通的白边变黑，贡献 +1
// 按照先黑边后白边的顺序并查集维护即可
// 时间复杂度 O(mα(n))，其中 α 是反阿克曼函数
//
// NOTE: 感觉题解和题面就是两道题 :(
//
// INFO: Memory : ~3400 kB
//         Time : ~800 ms

// Sample Input
// 1
// 9 10
// 1 2 1
// 2 3 0
// 3 4 1
// 4 5 0
// 5 6 1
// 6 7 0
// 7 8 1
// 8 1 0
// 2 9 0
// 9 6 1

// Sample Output
// 2

#include <iostream>
#include <vector>
using namespace std;

int st[200005];
inline int find(int x) {
  return st[x] == x ? x : st[x] = find(st[x]);
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> es;

  for (int i = 0; i <= n; i++)
    st[i] = i;

  for (int i = 1; i <= m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    if (c)
      st[find(u)] = find(v);
    else
      es.push_back({u, v});
  }

  int cnt = 0;
  for (auto e : es) {
    int u = e.first, v = e.second;
    if (find(u) == find(v))
      cnt++;
    else {
      st[find(u)] = find(v);
    }
  }

  cout << cnt << "\n";
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
