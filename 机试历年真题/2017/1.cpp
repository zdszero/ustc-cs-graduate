#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
  string tmp;
  int flag = 0;
  ifstream ifs("./input1.txt");
  while (ifs >> tmp) {
    if (flag) {
      cout << " ";
    }
    flag = 1;
    tmp[0] = toupper(tmp[0]);
    cout << tmp;
  }
  return 0;
}
