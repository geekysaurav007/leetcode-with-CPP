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
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* s = NULL;
    void inorder(TreeNode* root, int start) {
        if (root == NULL) {
            return;
        }
        if (root->val == start) {
            s = root;
        }
        if (root->left)
            parent[root->left] = root;
        inorder(root->left, start);
        if (root->right)
            parent[root->right] = root;
        inorder(root->right, start);
    }
    int BFS(TreeNode* target) {
        unordered_set<int> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target->val);
        int k=0;
        while (!q.empty()) {
            int n = q.size();
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
           if(!q.empty()) k++;
        }
        return k;
    }

    int amountOfTime(TreeNode* root, int start) {
        inorder(root, start);
        int k = 0;
        return BFS(s);
    }
};