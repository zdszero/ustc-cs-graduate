#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[]) {
  float X;
  int N;
  cin >> X >> N;
  int Y = X * 100;
  map<int, int> occ;
  occ[0] = occ[Y] = 1;
  for (int i = 0; i < N - 1; i++) {
    int div;
    do {
      div = rand() % (Y - 1) + 1;
    } while (occ.count(div));
    occ[div] = 1;
  }
  auto prev = occ.begin();
  for (auto it = next(occ.begin()); it != occ.end(); it++) {
    printf("%.2f ", (float)(it->first - prev->first) / 100);
    prev++;
  }
  return 0;
}
