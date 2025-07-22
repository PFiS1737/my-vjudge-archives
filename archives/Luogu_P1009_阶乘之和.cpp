// INFO: Tags: 高精度
//
// 题目描述
// 用高精度计算出 S = 1! + 2! + 3! + ... + n!（n <= 50）。
// 其中 `!` 表示阶乘，定义为 n! = n x (n-1) x (n-2) x ... x 1。例如，5! = 5 x i4 x 3 x 2 x 1 = 120。
//
// 输入格式
// 一个正整数 n。
//
// 输出格式
// 一个正整数 S，表示计算结果。
//
// 说明/提示
// 对于 100% 的数据，1 <= n <= 50。

// Sample Input
// 5

// Sample Output
// 153

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int *s = new int[100];
  int i = 0;
  int *f = new int[100];
  int j = 1;
  f[0] = 1;

  auto add = [&]() {
    int car = 0;
    for (int p = 0; p < max(i, j); p++) {
      int sum = (p < i ? s[p] : 0) + (p < j ? f[p] : 0) + car;
      s[p] = sum % 10;
      car = sum / 10;
    }
    i = max(i, j);
    if (car) {
      s[i++] = car;
    }
  };

  auto mul = [&](int o) {
    int car = 0;
    for (int p = 0; p < j; p++) {
      int sum = f[p] * o + car;
      f[p] = sum % 10;
      car = sum / 10;
    }
    while (car) {
      f[j++] = car % 10;
      car /= 10;
    }
  };

  for (int k = 1; k <= n; k++) {
    mul(k);
    add();
  }

  for (int k = i - 1; k >= 0; k--) {
    cout << s[k];
  }
  cout << endl;

  return 0;
}
