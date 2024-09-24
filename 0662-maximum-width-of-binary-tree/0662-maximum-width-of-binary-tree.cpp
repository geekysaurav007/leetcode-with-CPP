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
    typedef unsigned long long l;
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        l maxi = 0;
        while (!q.empty()) {
            l n = q.size();
            // accessing the front node ka index or us level ka left most
            l left = q.front().second;
            // accessing the back node ka index or us level ka right most
            l right = q.back().second;
            // calculate the maximmum in each level
            maxi = max(maxi, right - left + 1);

            for (int i = 0; i < n; i++) {
                // take out vthe curr node
                TreeNode* curr = q.front().first;
                // us node ka index nikalo
                l index = q.front().second;
                q.pop();
                if (curr->left) {
                    q.push({curr->left, (2 * index + 1)}); // left side
                }
                if (curr->right) {
                    q.push({curr->right, (2 * index + 2)}); // right side
                }
            }
        }
        return maxi;
    }
};