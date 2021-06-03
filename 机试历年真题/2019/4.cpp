#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<char>> &subsets) {
  cout << '{';
  int flag1 = 0;
  for (auto &a : subsets) {
    if (flag1) cout << ',';
    cout << '{';
    int flag2 = 0;
    for (auto &b : a) {
      if (flag2) cout << ',';
      cout << b;
      flag2 = 1;
    }
    cout << '}';
    flag1 = 1;
  }
  cout << '}';
  cout << endl;
}

void solve(vector<char> &v, vector<vector<char>> &subsets, int idx) {
  if (idx == v.size()) {
    print(subsets);
    return;
  }
  for (int i = 0; i < subsets.size(); i++) {
    subsets[i].push_back(v[idx]);
    solve(v, subsets, idx + 1);
    subsets[i].pop_back();
  }
  subsets.push_back({v[idx]});
  solve(v, subsets, idx + 1);
  subsets.pop_back();
}

int main(int argc, char *argv[]) {
  ifstream ifs("./set.in");
  char c;
  vector<char> v;
  while (ifs >> c) {
    v.push_back(c);
  }
  vector<vector<char>> subsets;
  solve(v, subsets, 0);
  return 0;
}
