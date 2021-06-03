#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int16_t num;
  cin >> num;
  num = (num ^ (num >> 4) ^ (num >> 8) ^ (num >> 12)) & 0x000f;
  cout << num << endl;
  return 0;
}
