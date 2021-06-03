#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream ifs("./input4.txt");
  string s1, s2;
  int dp[1000][1000];
  while (ifs >> s1 >> s2) {
    int m = s1.length(), n = s2.length();
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (s1[i-1] == s2[j-1])
          dp[i][j] = dp[i-1][j-1] + 1;
        else
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
    cout << dp[m][n] << endl;
  }
  return 0;
}
