#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void reverseString(vector<char> &s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
      swap(s[i], s[j]);
    }
  }
};

int main() {
  Solution solution;
  vector<char> s = {'H', 'a', 'n', 'n', 'a', 'h'};
  solution.reverseString(s);
  for (auto c : s) {
    cout << c << " ";
  }
  cout << endl;
}