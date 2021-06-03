#include <fstream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>> &g, vector<int> &vis, vector<int> &tmp, int idx,
        int n) {
  if (vis[idx])
    return 0;
  vis[idx] = 1;
  tmp.push_back(idx);
  int ans = 1;
  for (int i = 0; i < n; i++) {
    if (g[idx][i]) {
      ans += dfs(g, vis, tmp, i, n);
    }
  }
  return ans;
}

int main(int argc, char *argv[]) {
  ifstream ifs("./graph.in");
  ofstream ofs("./graph.out");
  int n, m;
  ifs >> n >> m;
  vector<vector<int>> g(n, vector<int>(n, 0));
  vector<int> vis(n, 0);
  vector<int> ans, tmp;
  int maxval = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    ifs >> a >> b;
    g[a][b] = g[b][a] = 1;
  }
  for (int i = 0; i < n; i++) {
    if (vis[i])
      continue;
    int tmpval = dfs(g, vis, tmp, i, n);
    if (tmpval > maxval) {
      maxval = tmpval;
      ans = tmp;
    }
    tmp.clear();
  }
  for (int i = 0; i < ans.size(); i++) {
    if (i)
      ofs << " ";
    ofs << ans[i];
  }
  return 0;
}
