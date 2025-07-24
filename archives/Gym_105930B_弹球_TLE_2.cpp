// ISSUE: 超时(TLE)
//        暴力模拟做法，毫无悬念的超时

// Sample Input
// 3
// 5 2 8
// 4 2
// 6 4
// ? 10 4 -1 3
// + 8 2
// ? 3 3 -1 12
// ? 3 1 1 12
// - 4 2
// ? 3 3 -1 12
// ? 3 1 1 12
// ? 7 3 1 6
// 10 1 2
// 5 5
// ? 9 2 1 9
// ? 9 2 -1 9
// 1 0 1
// ? 0 0 1 1000000000

// Sample Output
// 1
// 4
// 2
// 2
// 4
// 4
// 2
// 2
// 0

#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int H, n, q;
    cin >> H >> n >> q;

    unordered_map<int, unordered_set<int>> mus;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      mus[x].insert(y);
    }

    for (int i = 0; i < q; i++) {
      char op;
      int x, y;
      cin >> op >> x >> y;

      switch (op) {
        case '+': {
          mus[x].insert(y);
          break;
        }
        case '-': {
          mus[x].erase(y);
          break;
        }
        case '?': {
          int vy, g;
          cin >> vy >> g;
          int vx = g >= x ? 1 : -1;

          while (x != g) {
            x += vx;
            y += vy;
            if (y == 0 || y == H || (mus.count(x) && mus[x].count(y))) {
              vy = -vy;
            }
          }

          cout << y << "\n";

          break;
        }
      }
    }
  }

  return 0;
}
