#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int x, y, k;
  cin >> x >> y >> k;
  int cnt = 0;
  for (int i = 0; i <= 8 && i <= x; i++) {
    for (int j = 0; j <= 8 - i && j <= y; j++) {
      if (8 - i - j <= k) {
        printf("%2d. %d红球，%d黄球，%d黑球\n", ++cnt, i, j, 8 - i - j);
      }
    }
  }
  return 0;
}
