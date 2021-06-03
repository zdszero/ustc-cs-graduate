#include <iostream>
using namespace std;

bool isPalindrome(const string &s) {
  int i = 0, j = s.length()-1;
  while (i < j) {
    if (s[i++] != s[j--])
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  string tmp;
  while (cin >> tmp) {
    if (isPalindrome(tmp))
      cout << "Y" << endl;
    else
      cout << "N" << endl;
  }
  return 0;
}
