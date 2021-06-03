#include <fstream>
#include <vector>
using namespace std;

int kmp(string &main, string &sub) {
  int len1 = main.length(), len2 = sub.length();
  // getNext
  vector<int> next(len2, 0);
  for (int i = 1; i < len2; i++) {
    if (sub[i] == sub[next[i-1]])
      next[i] = next[i-1]+1;
    else if (sub[i] == sub[0])
      next[i] = 1;
    else
      next[i] = 0;
  }
  for (int i = len2-1; i >= 1; i--) {
    next[i] = next[i-1];
  }
  next[0] = -1;
  int i = 0, j = 0;
  while (i < len1 && j < len2) {
    if (main[i] == sub[j]) {
      i++;
      j++;
    } else {
      if (next[j] == -1)
        i++;
      else
        j = next[j];
    }
  }
  if (j == len2)
    return i-j;
  return -1;
}

int main(int argc, char *argv[]) {
  ifstream ifs("./6.in");
  ofstream ofs("./6.out");
  string s1, s2;
  getline(ifs, s1);
  getline(ifs, s2);
  int ans = kmp(s1, s2);
  if (ans == -1) {
    ofs << 0 << endl;
  } else {
    ofs << ans+1 << " " << ans+s2.length() << endl;
  }
  return 0;
}
