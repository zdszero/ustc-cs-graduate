#include <fstream>
#include <vector>
using namespace std;

int flag = 0;

struct TreeNode {
  TreeNode *lchild, *rchild;
  char val;
  TreeNode(char val) : val(val) {}
};

TreeNode *buildTree(vector<char> &in, vector<char> &post) {
  auto make = [&](auto &&self, int l1, int r1, int l2, int r2) -> TreeNode *{
    if (l1 > r1)
      return nullptr;
    TreeNode *t = new TreeNode(post[r2]);
    int i;
    for (i = l1; i <= r1; i++)
      if (in[i] == post[r2])
        break;
    t->lchild = self(self, l1, i-1, l2, l2+i-1-l1);
    t->rchild = self(self, i+1, r1, l2+i-l1, r2-1);
    return t;
  };
  return make(make, 0, in.size()-1, 0, post.size()-1);
}

void inOrder(TreeNode *t, ostream &os) {
  if (!t)
    return;
  inOrder(t->lchild, os);
  if (flag) os << " ";
  os << t->val;
  flag = 1;
  inOrder(t->rchild, os);
}

int main(int argc, char *argv[]) {
  ifstream ifs("./4.in");
  ofstream ofs("./4.out");
  int n;
  ifs >> n;
  vector<char> in(n);
  vector<char> post(n);
  for (int i = 0; i < n; i++) ifs >> in[i];
  for (int i = 0; i < n; i++) ifs >> post[i];
  TreeNode *root = buildTree(in, post);
  inOrder(root, ofs);
  return 0;
}
