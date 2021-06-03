#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int depth;
int flag = 0;

struct TreeNode {
  TreeNode *lchild, *rchild;
  char val;
  TreeNode(char val) : val(val) {}
};

TreeNode *buildTree(vector<char> &v, int &idx) {
  if (v[idx] == '0') return nullptr;
  TreeNode *t = new TreeNode(v[idx]);
  t->lchild = buildTree(v, ++idx);
  t->rchild = buildTree(v, ++idx);
  return t;
}

int getDepth(TreeNode *t) {
  if (!t) return 0;
  return max(getDepth(t->lchild), getDepth(t->rchild)) + 1;
}

void postOrder(TreeNode *t, int dep) {
  if (!t) return;
  postOrder(t->lchild, dep + 1);
  if (dep <= depth / 2) {
    if (flag) cout << " ";
    flag = 1;
    cout << t->val;
  }
  postOrder(t->rchild, dep + 1);
}

int main(int argc, char *argv[]) {
  ifstream ifs("./tree.in");
  char c;
  vector<char> v;
  while (ifs >> c) v.push_back(c);
  int idx = 0;
  TreeNode *root = buildTree(v, idx);
  depth = getDepth(root);
  postOrder(root, 1);
  return 0;
}
