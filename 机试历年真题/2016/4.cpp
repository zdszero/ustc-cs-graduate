#include <fstream>
#include <vector>
using namespace std;

ifstream ifs("./4.in");
ofstream ofs("./4.out");

struct TreeNode {
  TreeNode *lchild, *rchild;
  char val;
  TreeNode(char val) : lchild(nullptr), rchild(nullptr), val(val) {}
};

void inOrder(TreeNode *t) {
  if (!t) return;
  inOrder(t->lchild);
  ofs << t->val << " ";
  inOrder(t->rchild);
}

TreeNode *buildTree(vector<char> &pre, vector<char> &post) {
  auto make = [&](auto &&self, int l1, int r1, int l2, int r2) -> TreeNode * {
    if (l1 > r1) return nullptr;
    TreeNode *t = new TreeNode(pre[l1]);
    if (l1 != r1) {
      int i;
      for (i = l2; i <= r2; i++)
        if (pre[l1 + 1] == post[i]) break;
      t->lchild = self(self, l1 + 1, l1 + 1 + i - l2, l2, i);
      t->rchild = self(self, l1 + 2 + i - l2, r1, i + 1, r2 - 1);
    }
    return t;
  };
  return make(make, 0, pre.size() - 1, 0, post.size() - 1);
}

int main(int argc, char *argv[]) {
  int n;
  ifs >> n;
  vector<char> pre(n), post(n);
  for (int i = 0; i < n; i++) {
    ifs >> pre[i];
  }
  for (int i = 0; i < n; i++) {
    ifs >> post[i];
  }
  TreeNode *root = buildTree(pre, post);
  inOrder(root);
  return 0;
}
