#include <fstream>
#include <iostream>
using namespace std;

struct TreeNode {
  TreeNode *lchild, *rchild;
  int val;
  TreeNode(int val) : lchild(nullptr), rchild(nullptr), val(val) {}
};

TreeNode *root;

void insertNode(int val) {
  if (!root) {
    root = new TreeNode(val);
    return;
  }
  TreeNode *t = root, *pre;
  while (t) {
    pre = t;
    if (val >= t->val)
      t = t->rchild;
    else
      t = t->lchild;
  }
  if (val >= pre->val)
    pre->rchild = new TreeNode(val);
  else
    pre->lchild = new TreeNode(val);
}

void dfs(TreeNode *t, int sum, int &max) {
  if (!t) return;
  if (!t->lchild && !t->rchild) {
    if (sum + t->val > max) {
      max = sum + t->val;
      return;
    }
  }
  if (t->rchild) dfs(t->rchild, sum + t->val, max);
  if (t->lchild) dfs(t->lchild, sum + t->val, max);
}

int main(int argc, char *argv[]) {
  ifstream ifs("./tree.in");
  int num;
  while (ifs >> num) insertNode(num);
  int lhs_max = 0, rhs_max = 0;
  dfs(root->lchild, 0, lhs_max);
  dfs(root->rchild, 0, rhs_max);
  int ans = root->val + lhs_max + rhs_max;
  cout << ans;
  return 0;
}
