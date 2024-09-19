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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        bool ltor = true;
        if (root == NULL)
            return ans;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp(n);
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();  // take out the node
                q.pop(); //pop it
                int index = ltor ? i : n - 1 - i; //choose the index according to flag.
                temp[index] = node->val; // insert rthe val
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ltor = !ltor; // negate the value after every level
            ans.push_back(temp);
        }
        return ans;
    }
};