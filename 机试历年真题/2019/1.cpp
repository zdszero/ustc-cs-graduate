#include <iostream>
using namespace std;

int w[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char m[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

bool isValid(string &s) {
  int sum = 0;
  for (int i = 0; i < 17; i++) {
    if (!isdigit(s[i])) {
      return false;
    }
    sum += w[i] * (s[i] - '0');
  }
  return (m[sum % 11] == s[17]);
}

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  cout << (isValid(s) ? "YES" : "NO");
  return 0;
}
