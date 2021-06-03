#include <fstream>
#include <queue>
#include <sstream>
#include <unordered_map>
using namespace std;

struct TreeNode {
  TreeNode *lchlid, *rchild;
  char val;
  TreeNode(char val) : lchlid(nullptr), rchild(nullptr), val(val) {}
};

int main(int argc, char *argv[]) {
  ifstream ifs("./input_3.txt");
  ofstream ofs("./output_3.txt");
  unordered_map<char, TreeNode *> nodeMap;
  char a, b, c;
  string line;
  TreeNode *root, *t, *l, *r;
  ifs >> a;
  root = new TreeNode(a);
  nodeMap[a] = root;
  ifs.putback(a);
  while (getline(ifs, line)) {
    istringstream iss(line);
    iss >> a >> b;
    if (!nodeMap[a]) {
      nodeMap[a] = new TreeNode(a);
    }
    if (!nodeMap[b]) {
      nodeMap[b] = new TreeNode(b);
    }
    t = nodeMap[a];
    l = nodeMap[b];
    t->lchlid = l;
    if (iss >> c && !nodeMap[c]) {
      r = new TreeNode(c);
      nodeMap[c] = r;
      t->rchild = r;
    }
  }
  int size = 1, level = 1;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    int newSize = 0;
    int flag = level % 2;
    if (flag) ofs << level << ": ";
    for (int i = 0; i < size; i++) {
      if (flag && i != 0) ofs << " ";
      t = q.front();
      q.pop();
      if (flag) ofs << t->val;
      if (t->lchlid) {
        q.push(t->lchlid);
        newSize++;
      }
      if (t->rchild) {
        q.push(t->rchild);
        newSize++;
      }
    }
    if (flag) ofs << endl;
    size = newSize;
    level++;
  }
  return 0;
}
