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

/* abc*d?e */
bool check(const string &s, int idx) {
  int len = s.length();
  if (idx >= len || s[idx++] != 'a') return false;
  if (idx >= len || s[idx++] != 'b') return false;
  while (idx < len && s[idx++] == 'c');
  if (idx < len && s[idx] == 'e') return true;
  if (idx >= len || s[idx++] != 'd') return false;
  if (idx >= len || s[idx] != 'e') return false;
  return true;
}

int main(int argc, char *argv[]) {
  string s = readFile("./3.txt");
  int flag = 0;
  for (int i = 0; i < s.length(); i++) {
    if (check(s, i)) {
      cout << "找到abc*d?e匹配" << endl;
      return 0;
    }
  }
  cout << "没找到abc*d?e匹配" << endl;
  return 0;
}
