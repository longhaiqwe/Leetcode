#include "Tree.h"
#include <queue>

class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;

    queue<TreeNode *> que;
    que.push(root);

    int result = 0;
    while (!que.empty()) {
      int size = que.size();
      result++;

      for (int i = 0; i < size; i++) {
        TreeNode *cur = que.front();
        que.pop();

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
  int maxDepth = s.maxDepth(root);
  cout << maxDepth << " " << endl;
}