#include <fstream>
#include <vector>
using namespace std;

#define INF 0x7fffffff

int main(int argc, char *argv[]) {
  ifstream ifs("./road.in");
  ofstream ofs("./road.out");
  int cityCnt, roadCnt, src, dst;
  ifs >> cityCnt >> roadCnt >> src >> dst;
  vector<vector<int>> road(cityCnt+1, vector<int> (cityCnt+1, INF));
  vector<vector<int>> next(cityCnt+1, vector<int> (cityCnt+1, -1));
  for (int i = 0; i < roadCnt; i++) {
    int a, b, c;
    ifs >> a >> b >> c;
    road[a][b] = c;
    next[a][b] = b;
  }
  // floyed-warshall
  for (int k = 1; k <= cityCnt; k++) {
    for (int i = 1; i <= cityCnt; i++) {
      for (int j = 1; j <= cityCnt; j++) {
        if (road[i][k] != INF && road[k][j] != INF && road[i][k] + road[k][j] < road[i][j]) {
          road[i][j] = road[i][k] + road[k][j];
          next[i][j] = k;
        }
      }
    }
  }
  ofs << road[src][dst] << endl;
  int i = src;
  while (i != dst) {
    ofs << i << " ";
    i = next[i][dst];
  }
  ofs << dst;
  return 0;
}
