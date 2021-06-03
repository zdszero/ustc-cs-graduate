#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  double sum = 0, factor = 1;
  for (int i = 1; i <= n; i++) {
    factor /= i;
    sum += factor;
  }
  printf("%.4f", sum);
  return 0;
}
