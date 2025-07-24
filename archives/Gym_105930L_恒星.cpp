// INFO: Tags : -
//        URL : https://vjudge.net/problem/Gym-105930L
//
// Description
// 在天文学中，恒星分类是根据恒星的光谱特征对其进行的分类。大多数恒星目前根据摩根-肯纳（MK）系统进行分类，
// 使用字母 O、B、A、F、G、K 和 M，从最热的（O 型）到最冷的（M 型）依次排列。
// 每个字母类别下再使用数码进行细分，0 表示最热，9 表示最冷。例如，A8、A9、F0 和 F1 形成了从热到冷的序列。
// 显然，7 个字母和 10 个数码给我们提供了总共 70 种不同的类别，其中 O0 是最热的，M9 是最冷的。
// 给定两个类别，判断第一个类别是比第二个类别更热，更冷，还是相同。
//
// Input
// 有多组测试数据。第一行输入一个整数 T（1 ≤ T ≤ 103）表示测试数据组数，对于每组测试数据：
// 第一行输入两个长度为 2 的字符串，表示两个类别。
//
// Output
// 每组数据输出一行。
// • 若第一个类别比第二个类别更热，输出 hotter。
// • 若第一个类别比第二个类别更冷，输出 cooler。
// • 若第一个类别和第二个类别相同，输出 same。
//
// HACK: Solution
// 按题意模拟，先比较字母关系，再比较数字关系。
// 复杂度 O(1)。
//
// INFO: Memory : -
//         Time : ~50 ms

// Sample Input
// 5
// O2 O7
// M9 M2
// G2 G2
// A0 B9
// F8 K1

// Sample Output
// hotter
// cooler
// same
// cooler
// hotter

#include <iostream>
using namespace std;

int main() {
  int arr[100];
  arr['O'] = 1, arr['B'] = 2, arr['A'] = 3, arr['F'] = 4;
  arr['G'] = 5, arr['K'] = 6, arr['M'] = 7;

  int T;
  cin >> T;
  while (T--) {
    string a, b;
    cin >> a >> b;
    int x = a[0], y = b[0];
    if (arr[x] < arr[y]) {
      cout << "hotter\n";
    } else if (arr[x] > arr[y]) {
      cout << "cooler\n";
    } else {
      int n = a[1] - '0', m = b[1] - '0';
      if (n < m) {
        cout << "hotter\n";
      } else if (n > m) {
        cout << "cooler\n";
      } else {
        cout << "same\n";
      }
    }
  }
  return 0;
}
