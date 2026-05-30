/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, int child) {
        if(root == nullptr) return 0;

        if(root->left == nullptr && root->right == nullptr) {
            return (child == 1) ? root->val : 0;
        }

        return solve(root->left, 1) +
               solve(root->right, 0);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root, 0);
    }
};