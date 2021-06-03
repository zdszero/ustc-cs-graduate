#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  long long a, b, c;
  cin >> a >> b;
  c = a ^ b;
  int ans = 0;
  for (int i = 0; i < 64; i++) {
    ans += (c & 1);
    c >>= 1;
  }
  cout << ans;
  return 0;
}
