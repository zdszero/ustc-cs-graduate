#include <fstream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream ifs("./expr.in");
  ofstream ofs("./expr.out");
  vector<char> v;
  stack<char> opStk;
  unordered_map<char, int> priority;
  priority['('] = 0;
  priority['+'] = priority['-'] = 1;
  priority['*'] = priority['/'] = 2;
  char c;
  while (ifs >> c)
    v.push_back(c);
  for (char c : v) {
    if (isalpha(c)) {
      ofs << c;
      continue;
    }
    if (c == '(') {
      opStk.push('(');
      continue;
    }
    if (c == ')') {
      char ch;
      while (1) {
        ch = opStk.top();
        opStk.pop();
        if (ch == '(')
          break;
        ofs << ch;
      };
      continue;
    }
    while (!opStk.empty() && priority[c] < priority[opStk.top()]) {
      char op = opStk.top();
      opStk.pop();
      ofs << op;
    }
    opStk.push(c);
  }
  while (!opStk.empty()) {
    char ch = opStk.top();
    opStk.pop();
    ofs << ch;
  }
  return 0;
}
