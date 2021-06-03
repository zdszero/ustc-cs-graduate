#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  vector<int> v;
  v.reserve(4);
  cout << v.size() << endl;
  v.push_back(5);
  cout << v.size() << endl;
  v.pop_back();
  cout << v.size() << endl;
  return 0;
}
