#include <iostream>
using namespace std;

char hexchar[] = {'0', '1',  '2', '3', '4', '5', '6', '7',
                  '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

int main(int argc, char *argv[]) {
  int num;
  cin >> num;
  int st[32];
  int i = 0;
  while (num) {
    st[i++] = num % 16;
    num /= 16;
  }
  while (--i >= 0) {
    cout << hexchar[st[i]];
  }
  return 0;
}
