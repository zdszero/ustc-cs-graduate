#include <fstream>
#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream ifs("./4.in");
  map<string, int> occMap;
  string tmp;
  while (ifs >> tmp) {
    occMap[tmp]++;
  }
  for (auto it : occMap) {
    cout << it.first << " " << it.second << endl;
  }
  return 0;
}
