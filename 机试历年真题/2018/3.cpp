#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

/* 返回-1时表示当前的硬币选择不能满足要求，不断递归直到得到不是-1的结果或者遍历完所有组合返回-1 */
int solve(vector<int> &v, int total, int idx) {
  if (total < 0) return -1;
  if (total == 0) return 0;
  for (int i = idx; i >= 0; i--) {
    int tmp = solve(v, total - v[i], i);
    if (tmp == -1) continue;
    return tmp + 1;
  }
  return -1;
}

int main(int argc, char *argv[]) {
  ifstream ifs("./input3.txt");
  int n, total;
  ifs >> total >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) ifs >> v[i];
  sort(v.begin(), v.end());
  int tmp = solve(v, total, v.size() - 1);
  cout << (tmp == -1 ? 0 : tmp);
  return 0;
}
