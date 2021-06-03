#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream ifs("./5.in");
  ofstream ofs("./5.out");
  int n;
  ifs >> n;
  int cnt = 0;
  vector<vector<int>> b(n, vector<int> (n, 0));
  vector<pair<int, int>> loc;
  loc.reserve(n);
  auto dfs = [&](auto &&self, int i) -> void {
    auto isValid = [&](int i, int j) {
      for (auto &p : loc)
        if (p.first == i || p.second == j || abs(p.first - i) == abs(p.second - j))
          return false;
      return true;
    };
    if (i == n) {
      cnt++;
      return;
    }
    for (int j = 0; j < n; j++) {
      if (!isValid(i, j))
        continue;
      b[i][j] = 1;
      loc.push_back(make_pair(i, j));
      self(self, i+1);
      b[i][j] = 0;
      loc.pop_back();
    }
  };
  dfs(dfs, 0);
  ofs << cnt << endl;
  return 0;
}
