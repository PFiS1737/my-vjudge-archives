// INFO: Tags : 预处理 BFS
//        URL : https://vjudge.net/problem/Gym-105930I
//
// Description
// 考虑一个 3 行 3 列的网格。网格里的每个格子都写着一个整数。从 1 到 9 的每个整数在网格中恰好出现一次。
// 您可以对网格执行以下三种操作。
// ![](https://cdn.vjudge.net.cn/e5115b7da6cc42f20c7908e634bf05b3)
// - 循环右移某一行
// - 循环下移某一列
// - 整体顺时针旋转 90 度
// 给定两个这样的网格，求将第一个网格转换为第二个网格所需的最小操作次数。
//
// Input
// 有多组测试数据。第一行输入一个整数 T（1 ≤ T ≤ 2×10^5）表示测试数据组数。对于每组测试数据：
// 对于前三行，第 i 行输入一个字符串 a_(i,1)a_(i,2)a_(i,3) (1 ≤ a_(i,j) ≤ 9)，表示第一个网格的第 i 行。
// 对于接下来的三行，第 i 行输入一个字符串 b_(i,1)b_(i,2)b_(i,3) (1 ≤ b_(i,j) ≤ 9)，表示第二个网格的第 i 行。
//
// Output
// 每组数据输出一行。如果可以将第一个网格转换为第二个网格，则输出一个整数，表示所需的最小操作次数；
// 如果无法完成转换，则输出 -1。
//
// HACK: Solution
// 每个格子里的数字其实不重要，只有每个格子最后去哪了才重要。
// 格子里的数字其实就是用来标识某个格子去哪了，具体是几不重要。
// 所以总是可以把初始状态映射成按顺序从 1 到 9（称为状态S），同时也得到了目标状态的映射。
// BFS 预处理从 S 到其它每个状态的最小步数，每次询问直接用映射后的目标状态查表输出答案即可。
// 复杂度O(n! × n + T × n)，其中 n = 9 是格子数量。
//
// INFO: Memory : ~8500 kB
//         Time : ~1000 ms

// Sample Input
// 4
// 293
// 678
// 514
// 624
// 579
// 183
// 624
// 579
// 183
// 293
// 678
// 514
// 123
// 456
// 789
// 321
// 456
// 789
// 123
// 456
// 789
// 123
// 456
// 789

// Sample Output
// 3
// 5
// -1
// 0

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

string shift_row(string s, int row) {
  int i = row * 3;
  swap(s[i], s[i + 1]);
  swap(s[i], s[i + 2]);
  return s;
}

string shift_col(string s, int col) {
  int i = col;
  swap(s[i], s[i + 3]);
  swap(s[i], s[i + 6]);
  return s;
}

string rotate(string s) {
  string t = s;
  s[0] = t[6];
  s[1] = t[3];
  s[2] = t[0];
  s[3] = t[7];
  s[5] = t[1];
  s[6] = t[8];
  s[7] = t[5];
  s[8] = t[2];
  return s;
}

vector<string> expand(string c) {
  return {
      shift_row(c, 0), shift_row(c, 1), shift_row(c, 2), shift_col(c, 0),
      shift_col(c, 1), shift_col(c, 2), rotate(c),
  };
};

unordered_map<string, int> pre(const string &s) {
  unordered_map<string, int> g;
  g[s] = 0;

  queue<string> q;
  q.push(s);

  while (q.size()) {
    string c = q.front();
    q.pop();
    for (string &s : expand(c)) {
      if (!g.count(s)) {
        g[s] = g[c] + 1;
        q.push(s);
      }
    }
  }

  return g;
}

int main() {
  auto g = pre("123456789");

  // PERF: ~1700ms -> ~1000ms
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  while (T--) {
    char x;

    // NOTE: 根据输入顺序创建到标准状态的映射
    unordered_map<char, char> map;
    for (int i = 0; i < 9; i++) {
      cin >> x;
      map[x] = '1' + i;
    }

    // NOTE: 根据映射创建目标状态
    string d = "";
    for (int i = 0; i < 9; i++) {
      cin >> x;
      d += map[x];
    }

    if (g.count(d)) {
      cout << g[d] << "\n";
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}
