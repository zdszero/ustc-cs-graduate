#include <fstream>
using namespace std;

int main() {
  ifstream ifs("./2.in");
  ofstream ofs("./2.out");
  int sum = 0, num;
  while (ifs >> num)
    sum += num;
  ofs << sum;
  return 0;
}
