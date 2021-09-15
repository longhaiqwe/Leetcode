#include "Tree.h"
#include <queue>

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    queue<TreeNode *> que;
    if (root != nullptr)
      que.push(root);

    vector<vector<int>> result;
    while (!que.empty()) {
      int size = que.size();
      vector<int> vec;

      for (int i = 0; i < size; i++) {
        TreeNode *cur = que.front();
        que.pop();
        vec.push_back(cur->val);

        if (cur->left)
          que.push(cur->left);
        if (cur->right)
          que.push(cur->right);
      }
      result.push_back(vec);
    }
    return result;
  }
};

int main() {
  vector<int> data = {1, 2, 3, null, 4, 5, 6, 7, null};
  TreeNode *root = NULL;
  root = CreateTree(data);

  Solution s;
  vector<vector<int>> result = s.levelOrder(root);
  for (auto m : result) {
    for (auto n : m) {
      cout << n << " ";
    }
    cout << endl;
  }
}