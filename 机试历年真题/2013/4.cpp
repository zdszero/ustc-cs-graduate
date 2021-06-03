#include <fstream>
#include <cmath>
using namespace std;

bool isOdd(int num) {
  for (int i = 2; i < sqrt(num); i++)
    if (num % i == 0)
      return false;
  return true;
}

int main(int argc, char *argv[]) {
  ifstream ifs("./4.in");
  ofstream ofs("./4.out");
  int num, ans = 0;
  ifs >> num;
  for (int i = 2; i <= num / 2; i++)
    if (isOdd(i) && isOdd(num - i))
      ans++;
  ofs << ans;
  return 0;
}
