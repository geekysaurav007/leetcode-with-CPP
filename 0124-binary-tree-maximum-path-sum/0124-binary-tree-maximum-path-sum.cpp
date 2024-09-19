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
    int helper(TreeNode *root,int &maxsum) {
        if (root == NULL)
            return 0;
        // calculate left part sum ?// max used because if any node has negative value,so just take 0
        int leftsum =  max(0,helper(root->left, maxsum));
         // calculate left part sum // max used because if any node has negative value,so just take 0
        int rightsum =max(0, helper(root->right, maxsum));
        // calculate umbrella sum -> root value+leftnode val+right node value
        int umbrella_sum = root->val + leftsum + rightsum;
        // calculate maximum sum upto a "X" node;
        maxsum = max(maxsum, umbrella_sum);
        // return the path which we have to choose-> root+left side or root+ right side
        return  max(leftsum, rightsum)+ root->val ;
    }
    int maxPathSum(TreeNode* root) {
        int maxsum = -9999999;
        helper(root,maxsum);
        return maxsum;
    }
};