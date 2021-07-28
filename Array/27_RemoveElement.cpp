#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int size = nums.size();
    int slow = 0;
    for (int fast = 0; fast < size; fast++) {
      if (nums[fast] != val) {
        nums[slow++] = nums[fast];
      }
    }
    return slow;
  }
};

int main() {
  Solution s;
  vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
  int val = 2;

  int len = s.removeElement(nums, val);
  cout << len << endl;
  for (int i = 0; i < len; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}