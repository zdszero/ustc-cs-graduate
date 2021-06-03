#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  long long num;
  vector<int> seven;
  cin >> num;
  while (num) {
    seven.push_back(num % 7);
    num /= 7;
  }
  for (int i = seven.size() - 1; i >= 0; i--)
    cout << seven[i];
  return 0;
}
