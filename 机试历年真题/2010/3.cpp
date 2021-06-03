#include <iostream>
using namespace std;

struct TreeNode {
  TreeNode *lchild, *rchild;
  int val;
  TreeNode(int val) : lchild(nullptr), rchild(nullptr), val(val) {}
};

TreeNode *root = nullptr;
int flag = 0;

void insertNode(int val) {
  if (!root) {
    root = new TreeNode(val);
    return;
  }
  TreeNode *t = root;
  TreeNode *pre;
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

void postOrder(TreeNode *t) {
  if (!t) return;
  postOrder(t->lchild);
  postOrder(t->rchild);
  if (flag) cout << " ";
  cout << t->val;
  flag = 1;
}

int main(int argc, char *argv[]) {
  int num;
  while (cin >> num) {
    if (num == 0) break;
    insertNode(num);
  }
  postOrder(root);
  return 0;
}
