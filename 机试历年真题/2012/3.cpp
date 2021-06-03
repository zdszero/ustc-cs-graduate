#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> idxMap;
unordered_map<int, string> nameMap;
unordered_map<int, vector<int>> adjMap;
vector<int> q;
int curIdx = 0;

void parseLine(const string &line) {
  string tmp;
  int i, j;
  for (i = 0; i < line.length(); i++)
    if (line[i] == '(')
      break;
  tmp = line.substr(0, i);
  if (!idxMap.count(tmp)) {
    nameMap[curIdx] = tmp;
    idxMap[tmp] = curIdx++;
  }
  int src = idxMap[tmp];
  for (j = ++i; j <= line.length(); j++) {
    if (line[j] == ',' || line[j] == ')') {
      tmp = line.substr(i, j - i);
      if (!idxMap.count(tmp)) {
        nameMap[curIdx] = tmp;
        idxMap[tmp] = curIdx++;
      }
      adjMap[src].push_back(idxMap[tmp]);
      i = ++j;
    }
  }
}

void dfs(vector<int> &vis, int src) {
  vis[src] = 1;
  for (int next : adjMap[src]) {
    if (next == -1)
      break;
    if (vis[next])
      continue;
    dfs(vis, next);
  }
  q.push_back(src);
}

int main(int argc, char *argv[]) {
  ifstream ifs("./task.in");
  ofstream ofs("./task.out");
  idxMap["NULL"] = -1;
  string line;
  while (getline(ifs, line)) {
    parseLine(line);
  }
  int size = curIdx;
  vector<int> vis(size, 0);
  for (int i = 0; i < size; i++) {
    if (vis[i])
      continue;
    dfs(vis, i);
  }
  for (int i = q.size() - 1; i >= 0; i--) {
    if (i != q.size()-1)
      ofs << " ";
    ofs << nameMap[q[i]];
  }
  return 0;
}
