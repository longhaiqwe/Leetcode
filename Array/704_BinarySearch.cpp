#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int search1(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size(); // 左闭右开

    while (left < right) {
      int middle = left + (right - left) / 2;
      if (target < nums[middle]) {
        right = middle;
      } else if (target > nums[middle]) {
        left = middle + 1;
      } else {
        return middle;
      }
    }
    return -1;
  }

  int search2(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1; // 左闭右闭

    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (target < nums[middle]) {
        right = middle - 1;
      } else if (target > nums[middle]) {
        left = middle + 1;
      } else {
        return middle;
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  int target = 9;
  cout << s.search1(nums, target) << endl;
  cout << s.search2(nums, target) << endl;
}