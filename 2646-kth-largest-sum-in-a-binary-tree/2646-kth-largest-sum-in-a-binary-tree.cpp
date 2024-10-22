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
    vector<long long> levelSums;

    // Level-order traversal (BFS)
    while (!q.empty()) {
        long long sum = 0;
        int levelSize = q.size();  // Number of nodes at the current level

        // Process each node in the current level
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (node != nullptr) {
                sum += node->val;  // Add node's value to the level sum

                // Push children for the next level
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
        }

        if (sum > 0)  
            levelSums.push_back(sum);
    }
    if (k > levelSums.size())
        return -1;
    nth_element(levelSums.begin(), levelSums.end() - k, levelSums.end());
    return levelSums[levelSums.size() - k];  // Return the k-th largest level sum
}
};