#include "Tree.h"
#include <queue>

class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr)
      return true;
    return compare(root->left, root->right);
  }

private:
  bool compare(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr) {
      return true;
    } else if (left == nullptr && right != nullptr) {
      return false;
    } else if (left != nullptr && right == nullptr) {
      return false;
    } else if (left->val != right->val) {
      return false;
    }

    return compare(left->left, right->right) &&
           compare(left->right, right->left);
  }
};

int main() {
  // vector<int> data = {1, 2, 3, null, 4, 5, 6, 7, null};
  // vector<int> data = {1, 2, 2, 3, 4, 4, 3};
  // vector<int> data = {1, 2, 2, null, 3, null, 3};
  // vector<int> data = {1, 2, 2, 3, null, null, 3};  // 不是想象中的树
  vector<int> data = {1, 2, 2, null, 3, 3};
  TreeNode *root = CreateTree(data);

  Solution s;
  cout << s.isSymmetric(root) << endl;
}