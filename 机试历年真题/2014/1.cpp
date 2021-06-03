#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  int digitCnt = 0, alphaCnt = 0, spaceCnt = 0, elseCnt = 0;
  for (char c : s) {
    if (isdigit(c))
      digitCnt++;
    else if (isalpha(c))
      alphaCnt++;
    else if (c == ' ')
      spaceCnt++;
    else
      elseCnt++;
  }
  printf("数字: %d\n", digitCnt);
  printf("字母: %d\n", alphaCnt);
  printf("空格: %d\n", spaceCnt);
  printf("其他字符: %d\n", elseCnt);
  return 0;
}
