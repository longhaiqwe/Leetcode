#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      // 第一个元素已经大于0，后面肯定不会再有满足条件的，可以直接返回结果了
      // 不做这个事情只是会浪费一点时间，对正确性无影响
      if (nums[i] > 0) {
        return result;
      }

      // 如果不看别人的解答，这里是不知道要这么去重的
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int left = i + 1;
      int right = nums.size() - 1;

      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if (sum < 0) {
          left++;
        } else if (sum > 0) {
          right--;
        } else {
          result.push_back(vector<int>{nums[i], nums[left], nums[right]});

          // 下面两句用来去重
          while (right > left && nums[right] == nums[right - 1])
            right--;
          while (right > left && nums[left] == nums[left + 1])
            left++;

          // 找到结果左右指针同时伸缩，一般双指针不会这么干，这是因为不重复的要求
          right--;
          left++;
        }
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<int> nums = {-1, 0, 1, 2, -1, -4};

  for (auto n : s.threeSum(nums)) {
    for (auto m : n) {
      cout << m << " ";
    }
    cout << endl;
  }
}