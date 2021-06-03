#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= n-2; i++) {
    for (int j = i+1; j <= n-1; j++) {
      for (int k = j+1; k <= n; k++) {
        printf("%d %d %d\n", i, j, k);
      }
    }
  }
  return 0;
}
