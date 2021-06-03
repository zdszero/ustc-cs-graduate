#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream ifs("./input3.txt");
  int num;
  vector<int> v(1, 0);
  while (ifs >> num)
    v.push_back(num);
  int n = v.size() - 1;
  int maxv = 0;
  map<int, vector<int>> dp;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      int diff = v[i] - v[j];
      if (!dp.count(diff))
        dp[diff] = vector<int>(n+1, 1);
      int tmp = dp[diff][j] + 1;
      dp[diff][i] = tmp;
      if (tmp > maxv)
        maxv = tmp;
    }
  }
  cout << maxv << endl;
  return 0;
}
