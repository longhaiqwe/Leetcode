#include "Tree.h"

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        if (root->left == nullptr && root->right != nullptr)
        {
            return 1 + minDepth(root->right);
        }

        if (root->left != nullptr && root->right == nullptr)
        {
            return 1 + minDepth(root->left);
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

int main()
{
    vector<int> data = {1, 2, 3, null, 4, 5, 6, 7, null};
    TreeNode *root = NULL;
    root = CreateTree(data);

    Solution s;
    int maxDepth = s.minDepth(root);
    cout << maxDepth << " " << endl;
}