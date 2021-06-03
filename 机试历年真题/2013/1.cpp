#include <fstream>
using namespace std;

int main() {
  ifstream ifs("./1.in");
  ofstream ofs("./1.out");
  int num, maxv = 0;
  while (ifs >> num)
    if (num > maxv)
      maxv = num;
  ofs << maxv;
  return 0;
}
