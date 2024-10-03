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
TreeNode* findRight(TreeNode * root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
    TreeNode* helper(TreeNode* root) {
        if (root->right == NULL)
            return root->left;
        else if (root->left == NULL)
            return root->right;
        TreeNode* rightval = root->right;
        TreeNode* rightPart = findRight(root->left);
        rightPart->right = rightval;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        if (root->val == key) {
            TreeNode* ans = helper(root);
            return ans;
        }
        TreeNode* dummy = root;
        while (root != NULL) {
            if (key < root->val) {
                if (root->left && root -> left->val == key) {
                    TreeNode* ans = helper(root->left);
                    root->left = ans;
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right && root->right->val == key) {
                    TreeNode* ans = helper(root->right);
                    root->right = ans;
                    break;
                } else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};