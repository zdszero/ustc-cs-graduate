#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int a, b, c;
  cin >> a >> b;
  c = a ^ b;
  int bits[32];
  int N = 0;
  if (c == 0)
    cout << 0;
  while (c) {
    bits[N++] = c & 1;
    c >>= 1;
  }
  for (int i = N-1; i >= 0; i--)
    cout << bits[i];
  return 0;
}
