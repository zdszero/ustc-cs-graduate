#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream ifs("./input4.txt");
  int n;
  ifs >> n;
  vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
  int a, b;
  while (ifs >> a >> b) {
    g[a][b] = g[b][a] = 1;
  }
  auto keyVertex = [&]() -> int {
    auto isConnected = [&](int idx) -> bool {
      vector<int> vis(n + 1, 0);
      vis[idx] = 1;
      auto dfs = [&](auto &&self, int idx) -> void {
        vis[idx] = 1;
        for (int i = 1; i <= n; i++)
          if (g[idx][i] && !vis[i])
            self(self, i);
      };
      dfs(dfs, idx == n ? 1 : idx + 1);
      for (int i = 1; i <= n; i++)
        if (!vis[i])
          return false;
      return true;
    };
    for (int i = 1; i <= n; i++)
      if (!isConnected(i))
        return i;
    return 0;
  };
  int key = keyVertex();
  if (key)
    cout << key;
  else
    cout << "not exist";
  return 0;
}
