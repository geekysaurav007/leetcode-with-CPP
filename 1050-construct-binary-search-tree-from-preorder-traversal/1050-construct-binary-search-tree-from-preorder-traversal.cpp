/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int index;
    TreeNode* buildBSTFromPreorder(vector<int>& preorder, int& index,
                                   int max) {
        if (index == preorder.size() || preorder[index] > max) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[index++]);

        root->left = buildBSTFromPreorder(preorder, index, root->val);
        root->right = buildBSTFromPreorder(preorder, index, max);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return buildBSTFromPreorder(preorder, index, INT_MAX);
    }
};