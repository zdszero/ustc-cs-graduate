#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
  int src, dst, weight;
  Edge(int src, int dst, int weight) : src(src), dst(dst), weight(weight) {}
};

struct Cmp {
  bool operator()(const Edge &lhs, const Edge &rhs) {
    return lhs.weight > rhs.weight;
  }
};

int main(int argc, char *argv[]) {
  ifstream ifs("./3.in");
  int n;
  ifs >> n;
  vector<int> subset(n+1, 0);
  int MaxIdx = 1;
  priority_queue<Edge, vector<Edge>, Cmp> edges;
  vector<Edge> mst;
  int a, b, c;
  while (ifs >> a >> b >> c) {
    edges.push(Edge(a, b, c));
  }
  while (!edges.empty() && mst.size() < n-1) {
    Edge e = edges.top();
    edges.pop();
    int set1 = subset[e.src], set2 = subset[e.dst];
    if (!set1 && !set2) {
      subset[e.src] = subset[e.dst] = MaxIdx++;
    } else if (set1 && set2) {
      if (set1 == set2)
        continue;
      for (auto &s : subset)
        if (s == set2)
          s = set1;
    } else {
      if (!set1) subset[e.src] = set2;
      if (!set2) subset[e.dst] = set1;
    }
    mst.push_back(e);
  }
  for (auto &e : mst) {
    printf("%d -- %d : %d\n", e.src, e.dst, e.weight);
  }
  return 0;
}
