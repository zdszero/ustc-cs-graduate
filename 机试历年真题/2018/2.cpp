#include <fstream>
#include <iostream>
#include <unordered_map>
using namespace std;

int getGap(int a, int b, int c, int d) { return a * 60 + b - c * 60 - d; }

int main(int argc, char *argv[]) {
  unordered_map<string, int> timeTrack;
  ifstream ifs("./input2.txt");
  int n;
  ifs >> n;
  string id, ans;
  /* start hour, start minite, end hour, end minute */
  int sh, sm, eh, em;
  int longest = 0;
  for (int i = 0; i < n; i++) {
    ifs >> id;
    ifs >> sh;
    ifs.ignore(1);
    ifs >> sm;
    ifs >> eh;
    ifs.ignore(1);
    ifs >> em;
    int tmp;
    // the next day
    if (eh <= sh && em <= sm) {
      tmp = 24 * 60 - getGap(eh, em, sh, sm);
    } else {
      tmp = getGap(sh, sm, eh, em);
    }
    timeTrack[id] += tmp;
  }
  for (auto it = timeTrack.begin(); it != timeTrack.end(); it++) {
    if (it->second > longest) {
      longest = it->second;
      ans = it->first;
    }
  }
  cout << ans;
  return 0;
}
