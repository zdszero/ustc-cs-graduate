#include <fstream>
#include <map>
#include <memory.h>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream ifs("./ticket.in");
  ofstream ofs("./ticket.out");
  int nums[10000];
  memset(nums, 0, 10000);
  int n, m;
  ifs >> n >> m;
  int a, b, c, flag;
  for (int i = 0; i < n; i++) {
    ifs >> a >> b >> c;
    flag = 1;
    for (int j = a; j < b; j++) {
      if (nums[j] + c > m) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      for (int j = a; j < b; j++) {
        nums[j] += c;
      }
    }
    ofs << flag << endl;
  }
  return 0;
}
