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

  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr)
      return root;

    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);

    return root;
  }

  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result;
    traversal(root, result);
    return result;
  }

  void traversal(TreeNode *cur, vector<int> &vec) {
    if (cur == nullptr)
      return;
    vec.push_back(cur->val);
    traversal(cur->left, vec);
    traversal(cur->right, vec);
  }
};

int main() {
  vector<int> data = {1, 2, 3, null, 4, 5, 6, 7, null};
  TreeNode *root = NULL;
  root = CreateTree(data);

  Solution s;
  vector<int> before = s.preorderTraversal(root);
  for (auto m : before) {
    cout << m << " ";
  }
  cout << endl;

  s.invertTree(root);

  vector<int> result = s.preorderTraversal(root);
  for (auto m : result) {
    cout << m << " ";
  }
  cout << endl;
}