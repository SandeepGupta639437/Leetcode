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
    void inorder(TreeNode* root, vector<int>& vals){
        if(!root) return;

        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    void fix(TreeNode* root, vector<int>& vals, int &idx){
        if(!root) return;

        fix(root->left, vals, idx);
        root->val = vals[idx++];
        fix(root->right, vals, idx);
    }

    void recoverTree(TreeNode* root) {
        vector<int> vals;

        inorder(root, vals);

        sort(vals.begin(), vals.end());

        int idx = 0;
        fix(root, vals, idx);
    }
};