#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream ifs("./number.in");
  ofstream ofs("./number.out");
  vector<int> nums;
  int num;
  while (ifs >> num) nums.push_back(num);
  int ans = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    nums[i] += max(nums[i-1], 0);
    ans = max(ans, nums[i]);
  }
  ofs << ans;
}
