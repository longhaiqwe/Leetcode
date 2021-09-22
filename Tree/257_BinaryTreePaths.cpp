#include "Tree.h"

class Solution {
   public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path;
        if (root == nullptr) {
            return result;
        }
        traversal(root, path, result);
        return result;
    }

   private:
    void traversal(TreeNode* cur, string path, vector<string>& result) {
        path += to_string(cur->val);

        if (cur->left == nullptr && cur->right == nullptr) {
            result.push_back(path);
            return;
        }

        if (cur->left) {
            traversal(cur->left, path + "->", result);
        }

        if (cur->right) {
            traversal(cur->right, path + "->", result);
        }
        return;
    }
};

int main() {
    vector<int> data = {1, 2, 3, null, 4, 5, 6, 7, null};
    TreeNode* root = NULL;
    root = CreateTree(data);

    Solution s;
    vector<string> paths = s.binaryTreePaths(root);
    for (auto path : paths) {
        cout << path << " " << endl;
    }
    cout << endl;
}