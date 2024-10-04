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
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    bool twoSum(vector<int>& ans, int target) {
        int i = 0, j = ans.size()-1;
        while (i < j) {
            if (ans[i] + ans[j] == target) {
                return true;
            } else if (ans[i] + ans[j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, ans);
        return twoSum(ans, k);
    }
};