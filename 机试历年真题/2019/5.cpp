#include <fstream>
#include <iostream>

using namespace std;

const int N = 100010;

int tree[N], mx[N], mx2[N], mxr[N],
    mx2r[N];  // longest, 2nd longest, next node of longest, next node of 2nd
              // longest

int down(int u) {
  if (!tree[u]) return 0;
  int llen = down(u << 1);
  int rlen = down((u << 1) + 1);

  if (llen > rlen)
    mxr[u] = u << 1, mx2r[u] = (u << 1) + 1;
  else
    mxr[u] = (u << 1) + 1, mx2r[u] = u << 1;

  mx[u] = max(llen, rlen) + tree[u];
  mx2[u] = min(llen, rlen) + tree[u];
  return mx[u];
}

void up(int u, int p) {
  if (!tree[u]) return;
  if (p != -1) {
    if (mxr[p] != u)  // parent's longest edge doesn't contain this node
    {
      if (mx[p] > mx[u]) {
        mx2[u] = mx[u];
        mx[u] = mx[p];
        mx2r[u] = mxr[u];
        mxr[u] = p;  // longest edge from parent
      } else if (mx[p] > mx2[u]) {
        mx2[u] = mx[p];
        mx2r[u] = p;
      }
    } else {
      if (mx2[p] > mx[u]) {
        mx2[u] = mx[u];
        mx[u] = mx2[p];
        mx2r[u] = mxr[u];
        mxr[u] = p;  // longest edge from parent
      } else if (mx2[p] > mx2[u]) {
        mx2[u] = mx2[p];
        mx2r[u] = p;
      }
    }
  }

  up(u << 1, u);
  up((u << 1) + 1, u);
}

int main() {
  ifstream ifs("expr.in");
  int i = 1;
  for (; ifs >> tree[i]; i++)
    ;
  down(1);
  up(1, -1);

  int res = 0;
  for (int j = 1; j <= i; ++j) res = max(res, mx[j] + mx2[j] - tree[j]);
  cout << res;
}
