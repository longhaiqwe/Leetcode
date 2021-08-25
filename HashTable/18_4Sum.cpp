#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      for (int j = i + 1; j < nums.size(); j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }

        int left = j + 1;
        int right = nums.size() - 1;

        while (left < right) {
          int64_t sum = (int64_t)nums[i] + nums[j] + nums[left] + nums[right];
          if (sum < target) {
            left++;
          } else if (sum > target) {
            right--;
          } else {
            result.push_back(
                vector<int>{nums[i], nums[j], nums[left], nums[right]});

            while (right > left && nums[right] == nums[right - 1]) {
              right--;
            }
            while (right > left && nums[left] == nums[left + 1]) {
              left++;
            }

            left++;
            right--;
          }
        }
      }
    }

    return result;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 0, -1, 0, -2, 2};
  int target = 0;

  for (auto n : s.fourSum(nums, 0)) {
    for (auto m : n) {
      cout << m << " ";
    }
    cout << endl;
  }
}