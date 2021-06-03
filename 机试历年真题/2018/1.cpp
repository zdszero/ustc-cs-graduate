#include <iostream>
using namespace std;

int mcnt[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ycnt[] = {366, 365, 365, 365};
string dname[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Firaday"};

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  int tmp = n % 7;
  int year = 2000, month = 1, date = 1;
  int i = 0;
  while (n >= ycnt[i%4]) {
    n -= ycnt[i%4];
    year++;
    i++;
  }
  i = 0;
  if (year % 4 == 0)
    mcnt[1] = 29;
  while (n >= mcnt[i]) {
    n -= mcnt[i];
    month++;
    i++;
  }
  date += n;
  printf("%d-%d-%d %s", year, month, date, dname[tmp].c_str());
  return 0;
}
