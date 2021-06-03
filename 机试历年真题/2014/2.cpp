#include <iostream>
using namespace std;

bool isPalindrome(const string &s) {
  int i = 0, j = s.size()-1;
  while (i < j)
    if (s[i++] != s[j--])
      return false;
  return true;
}

string add(const string &s1, const string &s2) {
  int maxlen = max(s1.length(), s2.length());
  string ans(maxlen, '0');
  int i = s1.length()-1, j = s2.length()-1, k = maxlen-1;
  int carry = 0;
  while (i >= 0 && j >= 0) {
    int sum = s1[i--] - '0' + s2[j--] - '0' + carry;
    carry = sum / 10;
    ans[k--] = (sum % 10) + '0';
  }
  while (i >= 0) {
    int sum = s1[i] - '0' + carry;
    carry = sum / 10;
    ans[i--] = (sum % 10) + '0';
  }
  while (j >= 0) {
    int sum = s2[j] - '0' + carry;
    carry = sum / 10;
    ans[j--] = (sum % 10) + '0';
  }
  if (carry == 1)
    ans = "1" + ans;
  return ans;
}

string reverse(const string &s) {
  return string(s.rbegin(), s.rend());
}

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  int cnt = 0;
  while (!isPalindrome(s)) {
    s = add(s, reverse(s));
    cnt++;
  }
  cout << cnt;
  return 0;
}
