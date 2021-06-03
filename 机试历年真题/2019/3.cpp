#include <fstream>
#include <iostream>
#include <stack>
using namespace std;

int calc(int lhs, int rhs, char op) {
  if (op == '+')
    return lhs + rhs;
  else if (op == '-')
    return lhs - rhs;
  else if (op == '*')
    return lhs * rhs;
  else
    return lhs / rhs;
}

int main(int argc, char *argv[]) {
  ifstream ifs("./pre.in");
  string s;
  getline(ifs, s);
  stack<int> numStk;
  for (int i = s.size() - 1; i >= 0; i--) {
    char c = s[i];
    if (isspace(c)) continue;
    if (isdigit(c)) {
      numStk.push(c - '0');
      continue;
    }
    int lhs = numStk.top();
    numStk.pop();
    int rhs = numStk.top();
    numStk.pop();
    numStk.push(calc(lhs, rhs, c));
  }
  cout << numStk.top();
  return 0;
}
