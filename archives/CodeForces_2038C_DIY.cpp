// INFO: Tags : -
//        URL : https://vjudge.net/problem/CodeForces-2038C
//
// 给你一个由 n 个整数 a1, a2, ..., an 组成的列表。
// 你需要从列表中选取 8 个元素作为四个点的坐标。这四个点应该是边平行于坐标轴的矩形的角。
// 您的任务是选取坐标，使得到的矩形具有尽可能大的面积。
// 矩形可以是退化矩形，即其面积可以是 0。
// 每个整数在列表中出现的次数不限（或更少）。
//
// Input
// 第一行包含一个整数 t ( 1 ≤ t ≤ 25000 ) —— 测试用例数。
// 每个测试用例的第一行包含一个整数 n ( 8 ≤ n ≤ 2⋅10^5 )。
// 每个测试用例的第二行包含 n 个整数 a1, a2, ..., an ( −10^9 ≤ ai ≤ 10^9 )。
// 输入的附加限制：所有测试用例中 n 的总和不超过 2⋅10^5。
//
// Output
// 对于每个测试用例，打印答案如下：
// 如果不可能构造出符合语句限制条件的矩形，则打印包含 NO（不区分大小写）字样的一行；
// 否则，在第一行打印 YES（不区分大小写）。在第二行中，打印 8 个整数 x1, y1, x2, y2, x3, y3, x4, y4 —— 矩形各角的坐标。
// 您可以按照任意顺序打印角的坐标。
//
// HACK: Solution: 见代码注释
//
// INFO: Memory : ~3 MB
//         Time : ~500 ms

// Sample Input
// 3
// 16
// -5 1 1 2 2 3 3 4 4 5 5 6 6 7 7 10
// 8
// 0 0 -1 2 2 1 1 3
// 8
// 0 0 0 0 0 5 0 5

// Sample Output
// YES
// 1 2 1 7 6 2 6 7
// NO
// YES
// 0 0 0 5 0 0 0 5

#include <iostream>
#include <map>
#include <vector>
using namespace std;

void solve() {
  int n;
  cin >> n;

  map<int, int> an;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    an[a]++;
  }

  // NOTE: 我们每选一个点，意味着它一定在 an 中出现 2 次，
  //       如果选了一个点两次，则它一定出现了 4 次，以此类推，
  //       于是我们只需记录可供选择的点。
  vector<int> num;
  for (auto &a : an) {
    for (int i = 0; i < a.second / 2; i++) {
      num.push_back(a.first);
    }
  }

  // NOTE: 如果可供选择的点数量小于 4，则一定无法构成四边形。
  if (num.size() < 4) {
    cout << "NO" << endl;
    return;
  }

  // NOTE: 否则可以构成四边形，
  //       我们从中选择最小和最大的两个点（注意上面遍历的 map，这里自然有序），
  //       然后输出即可。
  int a = num[0];
  int b = num[1];
  int c = num[num.size() - 1];
  int d = num[num.size() - 2];

  cout << "YES" << endl;
  cout << a << " " << b << " " << a << " " << c << " " << d << " " << b << " " << d << " "
       << c << endl;
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
