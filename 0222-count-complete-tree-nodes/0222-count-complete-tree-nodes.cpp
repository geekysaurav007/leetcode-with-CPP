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
    int countNodes(TreeNode* root) {
        int cnt=0;
        queue<TreeNode*> q;
        if (root == NULL) {
            return 0;
        }
        q.push(root);
        while (!q.empty()) {
            vector<int> ans;
            for (int i = 0; i < q.size(); i++) {
                TreeNode* curr = q.front();
                q.pop();
                ans.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            cnt+=ans.size();
        }
        return cnt;
    }
};