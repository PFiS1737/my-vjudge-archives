//  INFO: Tags : DFS
//         URL : https://vjudge.net/problem/Gym-105442G
//
//  INFO: Memory : -
//          Time : ~50 ms

// Sample Input
// 4
// 773
// 300007
// 11
// 30007

// Sample Output
// 3
// 2
// 1
// 0

#include <algorithm>
#include <iostream>
using namespace std;

bool is_prime(int n) {
  if (n <= 1)
    return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int dfs(string s, int n) {
  if (s.empty()) {
    return n;
  }

  int ans = n;
  for (size_t i = 0; i < s.size(); i++) {
    string ns = s.substr(0, i) + s.substr(i + 1);

    if (ns.empty())
      continue;

    if (ns[0] == '0') {
      ans = max(ans, dfs(ns, n));
      continue;
    }

    if (is_prime(stoi(ns))) {
      ans = max(ans, dfs(ns, n + 1));
    }
  }

  return ans;
}

void solve() {
  string s;
  cin >> s;

  if (!is_prime(stoi(s))) {
    cout << "0\n";
    return;
  }

  cout << dfs(s, 1) << endl;
}

int main() {
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
