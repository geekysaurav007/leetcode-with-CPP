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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (root == NULL)
            return -1;

        queue<TreeNode*> q;
        q.push(root);
        vector<long long> ans;
        while (!q.empty()) {
            long long sum = 0;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node != NULL) {
                    sum += node->val;

                    if (node->left != NULL)
                        q.push(node->left);
                    if (node->right != NULL)
                        q.push(node->right);
                }
            }

            if (sum > 0)
                ans.push_back(sum);
        }
        if (k > ans.size())
            return -1;
        nth_element(ans.begin(), ans.end() - k, ans.end());
        return ans[ans.size() - k];
    }
};