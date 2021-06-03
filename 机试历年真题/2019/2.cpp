#include <iostream>
#include <bitset>
using namespace std;

int main(int argc, char *argv[]) {
  int num;
  cin >> num;
  bitset<32> bits(num);
  if (bits.count() != 2) {
    cout << "NO";
  } else {
    int a[2], idx = 0, tmp = num;
    for (int i = 0; i < 32; i++) {
      if (tmp & 1)
        a[idx++] = i;
      tmp >>= 1;
    }
    printf("%d = 2^%d + 2^%d\n", num, a[0], a[1]);
  }
  return 0;
}
