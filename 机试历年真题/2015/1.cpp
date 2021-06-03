#include <iostream>
using namespace std;

string s = "abcdefg";
int cnt = 1;
int size = 0;
char comb[5];

void solve(int idx) {
  if (size == 5) {
    printf("第%d种组合: %c, %c, %c, %c, %c\n", cnt++, comb[0], comb[1], comb[2],
           comb[3], comb[4]);
    return;
  }
  for (int i = idx; i < s.length(); i++) {
    comb[size++] = s[i];
    solve(i + 1);
    size--;
  }
}

int main(int argc, char *argv[]) {
  solve(0);
  return 0;
}
