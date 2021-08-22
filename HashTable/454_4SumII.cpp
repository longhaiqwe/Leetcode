#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                   vector<int> &nums4) {
    unordered_map<int, int> umap;

    for (int a : nums1) {
      for (int b : nums2) {
        umap[a + b]++;
      }
    }

    int count = 0;
    for (int c : nums3) {
      for (int d : nums4) {
        if (umap.find(0 - (c + d)) != umap.end()) {
          count += umap[0 - (c + d)];
        }
      }
    }

    return count;
  }
};

int main(void) {
  vector<int> A = {1, 2};
  vector<int> B = {-2, -1};
  vector<int> C = {-1, 2};
  vector<int> D = {0, 2};
  Solution s;

  cout << s.fourSumCount(A, B, C, D) << endl;
}