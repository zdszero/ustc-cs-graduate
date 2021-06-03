#include <fstream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
  TreeNode *lchild, *rchild;
  float val;
  TreeNode(float val) : lchild(nullptr), rchild(nullptr), val(val) {}
};

struct Cmp {
  bool operator()(TreeNode *l, TreeNode *r) {
    return l->val > r->val;
  }
};

unordered_map<TreeNode *, int> idxMap;
vector<string> ans;
string tmp;

void preOrder(TreeNode *root) {
  if (!root)
    return;
  if (!root->lchild && !root->rchild) {
    ans[idxMap[root]] = tmp;
    return;
  }
  tmp += "0";
  preOrder(root->lchild);
  tmp.pop_back();
  tmp += "1";
  preOrder(root->rchild);
  tmp.pop_back();
}

int main(int argc, char *argv[]) {
  ifstream ifs("./7.in");
  ofstream ofs("./7.out");
  float num;
  priority_queue<TreeNode *, vector<TreeNode *>, Cmp> pq;
  int idx = 0;
  while (ifs >> num) {
    TreeNode *t = new TreeNode(num);
    pq.push(t);
    idxMap[t] = idx++;
  }
  ans.resize(pq.size());
  while (pq.size() != 1) {
    TreeNode *t1 = pq.top();
    pq.pop();
    TreeNode *t2 = pq.top();
    pq.pop();
    TreeNode *t = new TreeNode(t1->val + t2->val);
    t->lchild = t1;
    t->rchild = t2;
    pq.push(t);
  }
  TreeNode *root = pq.top();
  preOrder(root);
  for (string &s : ans) {
    ofs << s << endl;
  }
  return 0;
}
