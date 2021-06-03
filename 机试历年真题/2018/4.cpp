#include <fstream>
#include <iostream>
using namespace std;

int lic(const string &s1, const string &s2, int i, int j) {
  if (i == 0 || j == 0) return 0;
  if (s1[i - 1] == s2[j - 1]) return lic(s1, s2, i - 1, j - 1) + 1;
  return max(lic(s1, s2, i - 1, j), lic(s1, s2, i, j - 1));
}

int main(int argc, char *argv[]) {
  ifstream ifs("./input4.txt");
  string s1, s2;
  while (ifs >> s1 >> s2) {
    cout << lic(s1, s2, s1.length() - 1, s2.length() - 1) << endl;
  }
  return 0;
}
