#include <iostream>
#include <vector>
using namespace std;

// bool表示当前数字是否通过加法计算得到
#define VEC vector<pair<int, bool>>

bool solve(VEC &nums) {
  int size = nums.size();
  if (size == 1) return (nums[0].first == 24);
  VEC tmp;
  // 选举nums中的第i个和第j个数字根据加法或乘法组成新的数字
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      // 将未被选择数字加入tmp中
      for (int k = 0; k < size; k++)
        if (k != i && k != j) tmp.push_back(nums[k]);
      tmp.push_back(make_pair(nums[i].first + nums[j].first, true));
      if (solve(tmp)) return true;
      tmp.pop_back();
      // 只有当选取的两个数字都不是通过加法计算得到时才能调用乘法对这两个数字进行计算
      if (!nums[i].second && !nums[j].second) {
        tmp.push_back(make_pair(nums[i].first * nums[j].first, false));
        if (solve(tmp)) return true;
      }
      tmp.clear();
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  VEC nums;
  int num;
  for (int i = 0; i < 4; i++) {
    cin >> num;
    nums.push_back(make_pair(num, false));
  }
  cout << (solve(nums) ? "YES" : "NO");
  return 0;
}
