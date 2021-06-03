#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream ifs("./graph.in");
  int n;
  ifs >> n;
  vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
  vector<int> vis(n + 1, 0);
  queue<int> q;
  int s, d;
  while (ifs >> s >> d && s != 0 && d != 0) {
    g[s][d] = g[d][s] = 1;
  }
  q.push(1);
  vis[1] = 1;
  int flag = 0;
  while (!q.empty()) {
    int tmp = q.front();
    q.pop();
    if (flag) cout << " ";
    flag = 1;
    cout << tmp;
    for (int i = 1; i <= n; i++) {
      if (g[tmp][i] && !vis[i]) {
        q.push(i);
        vis[i] = 1;
      }
    }
  }
  return 0;
}
