/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (root->left)
            parent[root->left] = root;
        inorder(root->left);
        if (root->right)
            parent[root->right] = root;
        inorder(root->right);
    }
    void BFS(TreeNode* target, int k, vector<int>& res) {
        unordered_set<int> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target->val);
        while (!q.empty()) {
            int n = q.size();
            if (k == 0)
                break;
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                // traverse left
                if (curr->left && !visited.count(curr->left->val)) {
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }
                // traverse right
                if (curr->right && !visited.count(curr->right->val)) {
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }
                // traverse the upward node;
                if (parent.count(curr) && !visited.count(parent[curr]->val)) {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            res.push_back(temp->val);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        inorder(root);
        vector<int> res;
        BFS(target, k, res);
          parent.clear();
        return res;
      
    }
};