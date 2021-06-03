#include <fstream>
#include <vector>
using namespace std;

int flag = 0;
ifstream ifs("./4.txt");
ofstream ofs("./4.out");

struct TreeNode {
  TreeNode *lchild, *rchild;
  int val;
  TreeNode(int val): val(val) {}
};

void postOrder(TreeNode *t) {
  if (!t)
    return;
  postOrder(t->lchild);
  postOrder(t->rchild);
  if (flag)
    ofs << " ";
  flag = 1;
  ofs << t->val;
}

int main(int argc, char *argv[]) {
  int n, rootIdx;
  int a, b, c;
  ifs >> n >> rootIdx;
  vector<TreeNode *> nodes(n+1, nullptr);
  ifs.putback(rootIdx+'0');
  while (ifs >> a >> b >> c) {
    if (!nodes[a]) nodes[a] = new TreeNode(a);
    if (!nodes[b] && b != 0) nodes[b] = new TreeNode(b);
    if (!nodes[c] && c != 0) nodes[c] = new TreeNode(c);
    nodes[a]->lchild = nodes[b];
    nodes[a]->rchild = nodes[c];
  }
  TreeNode *root = nodes[rootIdx];
  postOrder(root);
  return 0;
}
