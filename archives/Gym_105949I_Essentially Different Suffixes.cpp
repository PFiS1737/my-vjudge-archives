// INFO: Tags : 字典树
//        URL : https://vjudge.net/problem/Gym-105949I
//
// 给定 N 个字符串，求这些字符串本质不同的后缀个数。
// N ≤ 3 × 10^5 , ∑|Si| ≤ 3 × 10^5 。
//
// HACK: 官方题解
// 每个串翻转过来，变成本质不同的前缀个数。
// 可以通过直接把反串插入 trie 树，输出节点个数 −1 即可，
// 也可以通过别的字符串算法通过本题。
// 时间复杂度 O(∑|Si|)。
//
// INFO: Memory : ~33.6 MB
//         Time : ~170 ms

// Sample Input
// 3
// fbudpefs
// cfhjoofs
// edpouftu

// Sample Output
// 22

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int cnt = 0;

struct Trie {
  Trie *next[26] = {};

  int insert(const string &s) {
    Trie *p = this;
    for (char c : s) {
      int idx = c - 'a';
      if (!p->next[idx]) {
        p->next[idx] = new Trie();
        cnt++;
      }
      p = p->next[idx];
    }
    return cnt;
  }
};

int main() {
  int n;
  cin >> n;

  Trie *tr = new Trie();

  // NOTE: 字典树板子题，逆序插入字典树后统计一共有多少节点即可
  while (n--) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    tr->insert(s);
  }

  cout << cnt << endl;

  return 0;
}
