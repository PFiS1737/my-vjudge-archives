// INFO: Tags : -
//        URL : https://vjudge.net/problem/Gym-105442K
//
// INFO: Memory : ~100 kB
//         Time : ~630 ms

// Sample Input
// 2
// 3 6 2 5 2
// 7 4 3 1 4

// Sample Output
// 7

#include <iostream>
#include <limits>
using namespace std;

int main() {
  int n;
  cin >> n;
  int a, b, c, d, e;
  int ans = numeric_limits<int>::max();
  while (n--) {
    cin >> a >> b >> c >> d >> e;
    ans = min(ans, min(a + d, min(b + e, min(a + c + e, b + c + d))));
  }
  cout << ans << endl;
  return 0;
}
