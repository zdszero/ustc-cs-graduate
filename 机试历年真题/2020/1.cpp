#include <iostream>
using namespace std;

int gcd(int a, int b) {
  return (b == 0 ? a : gcd(b, a % b));
}

int main(int argc, char *argv[]) {
  int a, b;
  cin >> a >> b;
  if (b > a) swap(a, b);
  cout << gcd(a, b);
  return 0;
}
