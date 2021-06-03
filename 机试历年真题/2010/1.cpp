#include <iostream>
#include <fstream>
#include <list>
using namespace std;

int main(int argc, char *argv[]) {
  list<string> lines;
  string tmp;
  ifstream ifs("./input.txt");
  while (getline(ifs, tmp))
    lines.push_back(tmp);
  for (auto it = lines.begin(); it != lines.end(); it++) {
    for (int i = 0; i < it->length(); i++) {
      if (it->at(i) == '!' && i > 0)
        (*it)[i-1] = '0';
      else if (it->at(i) == '*')
        lines.erase(prev(it));
      else if (it->at(i) == '>') {
        int j;
        for (j = i-1; j >= 0 && it->at(j) != ' '; j--);
        for (; j >= 0 && it->at(j) == ' '; j--);
        if (j < 0)
          continue;
        for (; j >= 0 && it->at(j) != ' '; j--);
        (*it)[j+1] = toupper((*it)[j+1]);
      }
    }
  }
  for (auto &s : lines) {
    for (auto c : s) {
      if (isalpha(c) || c == ' ')
        cout << c;
    }
    cout << endl;
  }
  return 0;
}
