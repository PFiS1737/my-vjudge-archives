// INFO: Tags : -
//        URL : https://vjudge.net/problem/Gym-105851A
//
// 给定一个长度为 n 的仅由 0 和 1 组成的字符串 s ，你可以进行任意次（可以是 0 次）以下操作：
// • 选择一个首尾不同的子串，并删除这个子串。
// 例如，对于 s = 0001110，子串 001 的第一个字符和最后一个字符不同。选择该子串并删除后，原串变为 0110。
// 进行任意次操作后，字符串 s 的字典序 † 最小是多少？
// † 对于两个字符串 s 和 t ，设两字符串第一个不同的位置为 i 。若 si 是 0 且 ti 是 1 ，则称 s 的字典序小于 t 的字典序。
// 若这样的 i 不存在，则称长度较小的字符串字典序更小。空字符串的字典序小于任意其它字符串。
//
// 输入
// 每个测试文件包含多组测试数据。第一行包含测试数据的组数 T (1 ≤ T ≤ 10^5) 。每组测试数据的格式如下。
// 第一行包含一个整数 n (1 ≤ n ≤ 10^6)，表示字符串的长度。
// 第二行包含一个长度为 n 的字符串 s ，其中的字符仅有 0 和 1。
// 在每个测试文件内，保证所有测试数据的 n 之和不超过 10^6 。
//
// 输出
// 对于每组数据，输出一行字符串，代表可以通过操作得到的字典序最小的字符串。
// 特别地，当答案是空字符串时，请输出 “empty”。
//
// HACK: 官方题解
// 简单的分类讨论，分为以下几种情况：
// • 首位不同时，答案为empty
// • 首尾都为 0 时，假设 s 首尾都各加一个 1，答案为相邻的两个 1 之间的最少的 0。
// • 首尾都为 1 时，假设 s 首尾都各加一个 0，答案为相邻的两个 0 之间的最少的 1。
//
// INFO: Memory : ~600 kB
//         Time : ~60 ms

// Sample Input
// 4
// 2
// 01
// 4
// 0010
// 5
// 10011
// 5
// 11011

// Sample Output
// empty
// 0
// empty
// 11

#include <iostream>
using namespace std;

string find(string s, char c) {
  int i = -1, j = -1, n = s.size();
  string ans = s;
  for (int k = 0; k < n; k++) {
    if (s[k] == c) {
      j = i;
      i = k;
      if (i != -1 && j != -1) {
        string tmp = s.substr(j + 1, i - j - 1);
        if (tmp.size() < ans.size())
          ans = tmp;
      }
    }
  }
  return ans.empty() ? "empty" : ans;
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  // NOTE: 没有思考，题解说啥咱就写啥 (doge
  if (s[0] != s[n - 1])
    cout << "empty\n";
  else if (s[0] == '0')
    cout << find("1" + s + "1", '1') << '\n';
  else
    cout << find("0" + s + "0", '0') << '\n';
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
