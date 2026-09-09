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
    int n ;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int& idx,int start,int end){
        if(start>end)return NULL;

        TreeNode* root = new TreeNode;

        int val = preorder[idx];
        root->val = val;

        int i = start;
        while(i<n){
            if(inorder[i]==val)break;
            i++;
        }

        idx++;

        root->left = solve(preorder,inorder,idx,start,i-1);
        root->right = solve(preorder,inorder,idx,i+1,end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = preorder.size();
        int idx = 0;
        return solve(preorder,inorder,idx,0,n-1);
    }
};