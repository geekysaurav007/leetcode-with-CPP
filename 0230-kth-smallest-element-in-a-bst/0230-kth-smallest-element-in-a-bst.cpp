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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int cnt = 0;
        int ans;
        while (curr != NULL) {
            if (curr->left == NULL) {
                cnt++;
                if (cnt == k)
                    ans = curr->val;
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;
                while (pred->right != NULL &&  pred->right != curr) {
                    pred = pred->right;
                }
                // if left part not traversed
                if (pred->right == NULL) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = NULL;
                    cnt++;
                    if (cnt == k)
                        ans = curr->val;

                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};