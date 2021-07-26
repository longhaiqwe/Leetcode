#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string replaceSpace(string s) {
    // 统计空格个数
    int count = 0;
    for (auto c : s) {
      if (c == ' ') {
        count++;
      }
    };

    // 重新分配字符串长度
    int oldSize = s.size();
    s.resize(oldSize + 2 * count);
    int newSize = s.size();

    // 从后往前复制新的字符串
    for (int i = oldSize - 1, j = newSize - 1; i < j; i--, j--) {
      if (s[i] != ' ') {
        s[j] = s[i];
      } else {
        s[j] = '0';
        s[j - 1] = '2';
        s[j - 2] = '%';
        j -= 2;
      }
    }
    return s;
  }
};

int main() {
  string s = "We are happy";
  Solution solution;

  s = solution.replaceSpace(s);
  cout << s << endl;
}