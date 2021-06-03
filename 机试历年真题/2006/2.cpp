#include <iostream>
using namespace std;

// [_a-zA-Z][_a-zA-Z0-9]*
bool isValid(const string &s) {
  int i = 0;
  if (!(isalpha(s[i]) || s[i] == '_'))
    return false;
  for (++i; i < s.length(); i++) {
    if (!(isalpha(s[i]) || isdigit(s[i]) || s[i] == '_'))
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) { 
  string s;
  cin >> s;
  cout << isValid(s) << endl;
  return 0;
}
