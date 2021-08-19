#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> result_set;
    unordered_set<int> nums_set1(nums1.begin(), nums1.end());

    for (int num : nums2) {
      if (nums_set1.find(num) != nums_set1.end()) {
        result_set.insert(num);
      }
    }

    return vector<int>(result_set.begin(), result_set.end());
  }
};