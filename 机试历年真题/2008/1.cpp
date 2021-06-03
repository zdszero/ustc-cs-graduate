#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int num, cnt = 0;
  cin >> num;
  for (int i = 0; i < 32; i++) {
    cnt += (num & 1);
    num >>= 1;
  }
  cout << cnt;
  return 0;
}
