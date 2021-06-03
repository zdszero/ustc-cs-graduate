#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream ifs("./3.in");
  ofstream ofs("./3.out");
  int a[32];
  int N = 0;
  int num;
  ifs >> num;
  while (num) {
    a[N++] = num%2;
    num /= 2;
  }
  for (int i = N-1; i >= 0; i--) {
    ofs << a[i];
  }
  return 0;
}
