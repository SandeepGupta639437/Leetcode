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
    bool isCompleteTree(TreeNode* root) {

        queue<TreeNode*>que;

        que.push(root);

        bool flag = false;
        while(!que.empty()){
            int sz = que.size();
            while(sz--){
                auto node = que.front();
                que.pop();

                if(node->left == NULL) flag = true;
                if(node->left != NULL && flag) return false;
                if(node->left != NULL) que.push(node->left);

                if(node->right == NULL) flag = true;
                if(node->right != NULL && flag) return false;
                if(node->right != NULL) que.push(node->right);

            }
        }

        return true;
    }
};