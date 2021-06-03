#include <vector>
#include <fstream>
#include <sstream>
#include <climits>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream ifs("./input_4.txt");
  ofstream ofs("./output_4.txt");
  int n, k;
  ifs.ignore(2);
  ifs >> n;
  ifs.ignore(3);
  ifs >> k;
  ifs.ignore(1);
  vector<vector<int>> g(n+1, vector<int>(n+1, INT_MAX));
  vector<vector<int>> next(n+1, vector<int>(n+1, 0));
  for (int i = 0; i < n; i++) {
    g[i][i] = 0;
    next[i][i] = i;
  }
  string line;
  while (getline(ifs, line)) {
    istringstream iss(line);
    int src, dst, distance;
    iss >> src;
    while (iss >> dst >> distance) {
      g[src][dst] = distance;
      next[src][dst] = dst;
    }
  }
  for (int x = 0; x < n; x++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (g[i][x] == INT_MAX || g[x][j] == INT_MAX)
          continue;
        int sum = g[i][x] + g[x][j];
        if (sum < g[i][j]) {
          g[i][j] = sum;
          next[i][j] = x;
        }
      }
    }
  }
  int cur = 1;
  ofs << cur;
  while (cur != k) {
    cur = next[cur][k];
    ofs << " " << cur;
  }
  while (cur != n) {
    cur = next[cur][n];
    ofs << " " << cur;
  }
  return 0;
}
