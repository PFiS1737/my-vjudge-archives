// INFO: Tags : 位运算
//        URL : https://vjudge.net/problem/Gym-105992D
//
// Description
// gsh 喜欢位运算！今天，他在和一个 AI 进行博弈。
// 博弈规则如下：
// gsh 和 AI 轮流操作，gsh 先手。
// 他们操作两个非负整数 a 和 b，gsh 的目标是将其变为目标非负整数 x 和 y，
// 而 AI 需要阻止 gsh 达成目标。
// gsh 在自己的回合可以执行以下两种操作之一：
// a := a & v（按位与某个非负整数 v）。
// b := b ∣ v（按位或某个非负整数 v）。
// AI 在自己的回合可以执行以下两种操作之一：
// a := a ∣ v（按位或某个非负整数 v）。
// b := b & v（按位与某个非负整数 v）。
// 允许选择的 v 满足 0≤v<2^60。
// 双方都足够聪明，并且都会采取最优策略以赢得游戏。
// 若在 10^100 回合内，存在某一时刻 a = x 且 b = y，
// 则 gsh 获胜；否则，AI 获胜。
// 请你判断 gsh 是否必胜，若必胜，输出 Yes，否则输出 No。
//
// Input
// 第一行输入一个整数 T（1 ≤ T ≤ 10^5），表示数据组数。
// 接下来对每组数据输入一行四个非负整数 a, b, x, y（0 ≤ a,b,x,y < 2^60）。
//
// Output
// 对每组数据输出一行一个字符串 Yes 或 No。
//
// HACK: Solution
// 解法显然，
// 如果人不能一步就胜利，
// 那么 AI 就可以在第二步将人类第一步做出的操作完全抹除痕迹，
// 所以只需要考虑第一步的胜利情况就好了。
//
// INFO: Memory : -
//         Time : ~300 ms

// Sample Input
// 5
// 3 6 3 6
// 7 4 5 4
// 5 4 3 4
// 2 4 3 5
// 7 8 6 15

// Sample Output
// Yes
// Yes
// No
// No
// No

#include <iostream>
using namespace std;

void solve() {
  unsigned long long a, b, x, y;
  cin >> a >> b >> x >> y;
  cout << (((a & x) == x && b == y) || (a == x && (b | y) == y) ? "Yes\n" : "No\n");
}

int main() {
  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
