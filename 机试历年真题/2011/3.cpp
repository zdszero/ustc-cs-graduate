#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

string readFile(string filename) {
  ifstream ifs(filename);
  ostringstream oss;
  char c;
  while (ifs >> c) {
    oss.put(c);
  }
  return oss.str();
}

bool check(const string &s, int idx) {
  if (s[idx++] != 'a') return false;
  while (s[idx++] == 'b');
  if (s[idx] == 'e') return true;
  if (s[idx++] != 'd') return false;
  if (s[idx] != 'e') return false;
  return true;
}

int main(int argc, char *argv[]) {
  string s = readFile("./input.txt");
  int flag = 0;
  for (int i = 0; i < s.length(); i++) {
    if (check(s, i)) {
      flag = 1;
      break;
    }
  }
  if (flag) {
    cout << "找到abd*d?e匹配" << endl;
  } else {
    cout << "没找到abd*d?e匹配" << endl;
  }
  return 0;
}
