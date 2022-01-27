#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(const string &l, const string &r) {
  int lsize = l.size();
  int rsize = r.size();
  int maxv = max(l.size(), r.size());
  for (int i = 0; i < maxv; i++) {
    if (l[i % lsize] == r[i % rsize])
      continue;
    return l[i % lsize] > r[i % rsize];
  }
  return true;
};

int main(int argc, char *argv[]) {
  ifstream ifs("./number.in");
  vector<string> v;
  string s;
  while (ifs >> s)
    v.push_back(s);
  sort(v.begin(), v.end(), cmp);
  for (const auto &s : v) cout << s;
  return 0;
}
