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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        // right part not exixts
        while (curr != NULL) {
            if (curr->right == NULL) {
                ans.push_back(curr->val);
                curr = curr->left;
            }
            // Right part available
            else {
                TreeNode* rightchild = curr->right;
                while (rightchild->left != NULL && rightchild->left != curr) {
                    rightchild = rightchild->left;
                }
                // right part not traversed
                if (rightchild->left == NULL) {
                    rightchild->left = curr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
                // right part traversed-> break the link
                else {
                    rightchild->left = NULL;
                    curr = curr->left;
                }
            }
        }
       
        reverse(ans.begin(),ans.end());
         return ans;
    }

};
