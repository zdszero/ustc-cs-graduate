#include <fstream>
#include <vector>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main(int argc, char *argv[]) {
  ifstream ifs("./number.in");
  ofstream ofs("./number.out");
  int n;
  ifs >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    ifs >> a[i];
  int minVal, maxVal;
  minVal = maxVal = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] < minVal)
      minVal = a[i];
    if (a[i] > maxVal)
      maxVal = a[i];
  }
  ofs << minVal << " " << maxVal << " " << gcd(maxVal, minVal);
  return 0;
}
