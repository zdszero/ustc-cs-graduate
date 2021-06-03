#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream ifs("./number.in");
  vector<string> v;
  string s;
  while (ifs >> s) v.push_back(s);
  sort(v.begin(), v.end(), [](const string &l, const string &r) {
    int minv = min(l.size(), r.size());
    int maxv = max(l.size(), r.size());
    for (int i = 0; i < maxv; i++) {
      if (l[i % minv] == r[i % minv])
        continue;
      return l[i % minv] > r[i % minv];
    }
    return true;
  });
  for (auto &s : v) cout << s;
  return 0;
}
