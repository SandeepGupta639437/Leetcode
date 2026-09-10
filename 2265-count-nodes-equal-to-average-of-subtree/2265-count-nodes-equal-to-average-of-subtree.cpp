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
    int result = 0;
    int findSum(TreeNode* root,int& count){
        if(root==NULL)return 0;
        
        count++;
        int leftSum = findSum(root->left,count);
        int rightSum = findSum(root->right,count);

        return leftSum+rightSum+root->val;
    }
    void solve(TreeNode* root){
        if(root==NULL)return ;

        int count = 0;
        int sum = findSum(root,count);

        if(sum/count == root->val)result++;

        solve(root->left);
        solve(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return result;
    }
};