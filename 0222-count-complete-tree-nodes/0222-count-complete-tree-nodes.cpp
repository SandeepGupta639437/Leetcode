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
    int getLeftNode(TreeNode* root){
        if(root == NULL)return 0;
        return 1+getLeftNode(root->left);
    }
    int getRightNode(TreeNode* root){
        if(root == NULL)return 0;
        return 1+getRightNode(root->right);
    }
    int solve(TreeNode* root){
        if(root==NULL)return 0;

        int lh = getLeftNode(root);
        int rh = getRightNode(root);

        if(lh == rh)return (pow(2,lh)-1);

        return 1 + solve(root->left) + solve(root->right);
    }
    int countNodes(TreeNode* root) {
       return solve(root);
    }
};