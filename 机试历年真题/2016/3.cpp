#include <iostream>
#include <cmath>
using namespace std;

double func(double x) {
  return 2 * pow(x, 11) - 3 * pow(x, 8) - 5 * pow(x, 3) - 1;
}

double solve(double (*func) (double), double l, double r) {
  if (r - l < 0.00000001)
    return l;
  double mid = (r + l) / 2;
  double tmp = func(mid);
  if (tmp > 0) return solve(func, l, mid);
  else if (tmp < 0) return solve(func, mid, r);
  else return mid;
}

int main(int argc, char *argv[]) {
  printf("%.9f\n", solve(func, 1, 2));
  return 0;
}
