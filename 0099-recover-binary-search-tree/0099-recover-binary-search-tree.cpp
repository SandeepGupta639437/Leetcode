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

    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;
    void inorder(TreeNode* root){
        if(!root) return;

        inorder(root->left);
        if(prev!=NULL && (root->val < prev->val)){
            if(first==NULL){
                first = prev;
                middle = root;
            }else{
                last = root;
            }
        }

        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);

        if(first && last) swap(first->val,last->val);
        else if(first && middle) swap(first->val,middle->val);
    }
};