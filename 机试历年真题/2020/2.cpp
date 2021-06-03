#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void partition(vector<int> &a, int l, int r, int k) {
  if (l >= r) return;
  int base = a[l];
  int i = l, j = r;
  while (i < j) {
    while (i < j && a[j] >= base) j--;
    a[i] = a[j];
    while (i < j && a[i] <= base) i++;
    a[j] = a[i];
  }
  a[i] = base;
  if (k == i) return;
  else if (i < k) partition(a, i + 1, r, k);
  else partition(a, l, i - 1, k);
}

int main(int argc, char *argv[]) {
  int n, k;
  ifstream ifs("./array.in");
  ifs >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) ifs >> a[i];
  partition(a, 0, n - 1, k - 1);
  cout << a[k - 1];
  return 0;
}
