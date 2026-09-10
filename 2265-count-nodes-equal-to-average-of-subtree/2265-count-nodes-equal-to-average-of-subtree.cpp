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
    // int result = 0;
    // int findSum(TreeNode* root,int& count){
    //     if(root==NULL)return 0;
        
    //     count++;
    //     int leftSum = findSum(root->left,count);
    //     int rightSum = findSum(root->right,count);

    //     return leftSum+rightSum+root->val;
    // }
    // void solve(TreeNode* root){
    //     if(root==NULL)return ;

    //     int count = 0;
    //     int sum = findSum(root,count);

    //     if(sum/count == root->val)result++;

    //     solve(root->left);
    //     solve(root->right);
    // }

    int result = 0;

    pair<int,int> solve(TreeNode* root){
        if(root==NULL)return {0,0};

        auto p1 = solve(root->left);
        auto p2 = solve(root->right);

        int totalSum = p1.first + p2.first + root->val;
        int totalCnt = p1.second + p2.second + 1;

        int avg = (totalSum)/totalCnt;

        if(avg == root->val)result++;

        return {totalSum,totalCnt};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return result;
    }
};