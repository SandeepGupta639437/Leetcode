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
    int minDif=INT_MAX;

    void inOrder(TreeNode* root, TreeNode* &prev){
        if(root ==NULL)return ;
        inOrder(root->left,prev);
        if(prev !=NULL){
            minDif = min(minDif,root->val-prev->val);
        }
        prev=root;

        inOrder(root->right,prev);

    }

  

    int getMinimumDifference(TreeNode* root) {
        TreeNode* prev=NULL;

        inOrder(root,prev);
        return minDif;
        
    }
};