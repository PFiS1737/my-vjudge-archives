// INFO: Tags: DP
//
// 题目描述
// 给出正整数 n，要求按如下方式构造数列：
// 1. 只有一个数 n 的数列是一个合法的数列。
// 2. 在一个合法的数列的末尾加入一个正整数，但是这个正整数不能超过该数列最后一项的一半，可以得到一个新的合法数列。
// 请你求出，一共有多少个合法的数列。
// 两个合法数列 a, b 不同当且仅当两数列长度不同或存在一个正整数 i <= |a|，使得 a_i != b_i。
//
// 输入格式
// 输入只有一行一个整数，表示 n。
//
// 输出格式
// 输出一行一个整数，表示合法的数列个数。
//
// 说明/提示
// 对于全部的测试点，保证 1 ≤ n ≤ 10^3

// Sample Input
// 6

// Sample Output
// 6

#include <cstring>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int dp[n + 1]; //NOLINT
  memset(dp, 0, sizeof(dp));

  // NOTE: 以 6 开头，就是以 1、2、3、4、5 开头的，加上单独一个 6 的
  //       即：
  //         (6) 1
  //         (6) 2
  //         (6) 2 1
  //         (6) 3
  //         (6) 3 1
  //          6
  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
    for (int j = 1; j <= i / 2; j++) {
      dp[i] += dp[j];
    }
  }

  cout << dp[n] << endl;

  return 0;
}
