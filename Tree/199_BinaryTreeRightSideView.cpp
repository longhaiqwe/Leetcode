#include "Tree.h"
#include <queue>

class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    queue<TreeNode *> que;
    if (root != nullptr)
      que.push(root);

    vector<int> result;
    while (!que.empty()) {
      int size = que.size();

      for (int i = 0; i < size; i++) {
        TreeNode *cur = que.front();
        que.pop();
        if (i == (size - 1))
          result.push_back(cur->val);

        if (cur->left)
          que.push(cur->left);
        if (cur->right)
          que.push(cur->right);
      }
    }
    return result;
  }
};

int main() {
  vector<int> data = {1, 2, 3, null, 4, 5, 6, 7, null};
  TreeNode *root = NULL;
  root = CreateTree(data);

  Solution s;
  vector<int> result = s.rightSideView(root);
  for (auto n : result) {
    cout << n << " ";
  }
  cout << endl;
}