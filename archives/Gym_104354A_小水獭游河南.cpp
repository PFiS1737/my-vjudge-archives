// INFO: Tags : 暴力枚举
//        URL : https://vjudge.net/problem/Gym-104354A
//
// 小水獭来到河南旅游，它认为一个字符串 s 是 HENAN 的当且仅当存在两个**非空**字符串 a 和 b 满足如下三个条件：
// • a 由小写字母组成，且 a 中每种字母只出现了一次。
// • b 由小写字母组成，且 b 是回文串，也就是说将 b 翻转后得到的字符串和 b 相同。
// • 将 a 和 b 顺序拼接得到的字符串和 s 相同，也就是说 s = a + b。
// 例如 henan 是 HENAN 的，因为 henan=he+nan，此外也可分解为 hena+n。但 hhnan 和 ysmihoyocom 不是 HENAN 的。
// 现在给定一个字符串，请你帮助小水獭判断它是不是 HENAN 的。
//
// 输入格式
// **本题包含多组数据。**
// 第一行包含一个整数 T（1 ≤ T ≤ 10^3），表示数据组数。
// 对于每组数据：
// 一行包含一个由小写字母组成的字符串 s（1 ≤ |s| ≤ 10^5），表示小水獭询问的字符串。
// 保证所有数据的 Σ|s| ≤ 10^5。
//
// 输出格式
// 对于每组数据：
// 输出一行包含一个字符串。如果 s 是 HENAN 的，输出 HE；否则输出 NaN。
//
// HACK: 官方题解
// |a| ≤ |Σ| = 26，暴力枚举 a 判断 b 是否为是回文串即可，
// 时间复杂度 O(|Σ||s|)。
//
// INFO: Memory : -
//         Time : ~70 ms

// Sample Input
// 7
// henan
// hhnan
// ysmihoyocom
// a
// ab
// abc
// qwertyuiopasdfghjklzxcvbnm

// Sample Output
// HE
// NaN
// NaN
// NaN
// HE
// HE
// HE

#include <iostream>
using namespace std;

bool is_unique(string &s) {
  bool b[26] = {0};
  for (char c : s) {
    if (b[c - 'a'])
      return false;
    b[c - 'a'] = true;
  }
  return true;
}

bool is_palindrome(string &s) {
  for (size_t i = 0, j = s.size() - 1; i < j; i++, j--) {
    if (s[i] != s[j])
      return false;
  }
  return true;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    for (size_t i = 1; i < s.size(); i++) {
      string a = s.substr(0, i);
      string b = s.substr(i);
      if (!is_unique(a))
        break;
      if (is_palindrome(b)) {
        cout << "HE" << endl;
        goto a;
      }
    }
    cout << "NaN" << endl;
  a: {}
  }
  return 0;
}
