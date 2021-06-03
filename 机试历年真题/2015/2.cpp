#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int score = 0;
  for (int i = 0; i < 10; i++) {
    int a = rand() % 51, b = rand() % 51, c = rand() % 2;
    int guess, ans;
    char op;
    if (c == 0) {
      op = '+';
      ans = a + b;
    } else {
      op = '-';
      ans = a - b;
    }
    for (int j = 0; j < 2; j++) {
      printf("%d %c %d = ", a, op, b);
      scanf("%d", &guess);
      if (guess == ans) {
        cout << "right" << endl;
        score += (10 - j*5);
        break;
      } else {
        cout << "wrong" << endl;
      }
    }
  }
  printf("score = %d\n", score);
  return 0;
}
