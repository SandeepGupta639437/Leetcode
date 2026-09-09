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
    int count(TreeNode* root){
        if(root==NULL)return 0;

        return 1 + count(root->left) + count(root->right);
    }

    bool dfs(TreeNode* root,int totalNodes,const int& i){
        if(root==NULL)return true;
        if(i>totalNodes)return false;

        return dfs(root->left,totalNodes,2*i) && dfs(root->right,totalNodes,2*i+1);
    }

    bool isCompleteTree(TreeNode* root) {
        int totalNodesCnt = count(root);
        int i = 1;
        return dfs(root,totalNodesCnt,i);
    }
};