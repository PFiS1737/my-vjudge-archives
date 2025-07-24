// ISSUE: 超时(TLE)
//        使用对角线映射，快速找到下一个碰撞点，但还是超时了

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
#include <map>
#include <set>
using namespace std;

int H;

// NOTE: 按照对角线存储和查找
struct PosSet {
  map<int, set<int>> pp;
  map<int, set<int>> np;
  void push(int x, int y) {
    int pi = x - y, ni = x + y;
    pp[pi].insert(y);
    np[ni].insert(y);
  }
  void pop(int x, int y) {
    int pi = x - y, ni = x + y;
    pp[pi].erase(y);
    np[ni].erase(y);
  }
  pair<int, int> find(int x, int y, int vx, int vy) {
    if (vx > 0 && vy > 0) {
      int i = x - y;
      if (!pp.count(i))
        return {i + H, H};
      auto iter = pp[i].upper_bound(y);
      int ny = iter != pp[i].end() ? *iter : H;
      return {x + (ny - y), ny};
    } else if (vx > 0 && vy < 0) {
      int i = x + y;
      if (!np.count(i))
        return {i, 0};
      auto iter = np[i].lower_bound(y);
      int ny = iter != np[i].begin() ? *(--iter) : 0;
      return {x + (y - ny), ny};
    } else if (vx < 0 && vy > 0) {
      int i = x + y;
      if (!np.count(i))
        return {i - H, H};
      auto iter = np[i].upper_bound(y);
      int ny = iter != np[i].end() ? *iter : H;
      return {x - (ny - y), ny};
    } else if (vx < 0 && vy < 0) {
      int i = x - y;
      if (!pp.count(i))
        return {i, 0};
      auto iter = pp[i].lower_bound(y);
      int ny = iter != pp[i].begin() ? *(--iter) : 0;
      return {x - (y - ny), ny};
    } else {
      throw "Unexpected";
    }
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  while (T--) {
    int n, q;
    cin >> H >> n >> q;

    PosSet pos;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      pos.push(x, y);
    }

    for (int i = 0; i < q; i++) {
      char op;
      int x, y;
      cin >> op >> x >> y;

      switch (op) {
        case '+': {
          pos.push(x, y);
          break;
        }
        case '-': {
          pos.pop(x, y);
          break;
        }
        case '?': {
          int vy, g;
          cin >> vy >> g;
          int vx = g >= x ? 1 : -1;

          if (vx > 0) {
            while (true) {
              auto n = pos.find(x, y, vx, vy);
              int nx = n.first, ny = n.second;
              if (nx >= g) { // NOTE: 有可能 find 出来超了 g，就往回找，然后输出，下同
                cout << (ny - vy * (nx - g)) << "\n";
                break;
              } else {
                vy = -vy;
                x = nx;
                y = ny;
              }
            }
          } else {
            while (true) {
              auto n = pos.find(x, y, vx, vy);
              int nx = n.first, ny = n.second;
              if (nx <= g) {
                cout << (ny - vy * (g - nx)) << "\n";
                break;
              } else {
                vy = -vy;
                x = nx;
                y = ny;
              }
            }
          }

          break;
        }
      }
    }
  }

  return 0;
}
