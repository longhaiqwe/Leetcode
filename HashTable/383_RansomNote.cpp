#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int record[26] = {0};

    for (int i = 0; i < magazine.size(); i++) {
      record[magazine[i] - 'a']++;
    }

    for (int i = 0; i < ransomNote.size(); i++) {
      record[ransomNote[i] - 'a']--;
      if (record[ransomNote[i] - 'a'] < 0) {
        return false;
      }
    }

    return true;
  }
};

int main(void) {
  Solution s;
  string ransomNote;
  string magazine;
  while (1) {
    getline(cin, ransomNote);
    getline(cin, magazine);
    cout << s.canConstruct(ransomNote, magazine) << endl;
  }
}