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
    bool dfs(TreeNode* p, TreeNode* q) {
        // both null → trees are same
        if (!p && !q) return true;

        // one null, one not → trees differ
        if (!p || !q) return false;

        // values differ → trees differ
        if (p->val != q->val) return false;

        // check both subtrees
        return dfs(p->left, q->left) && dfs(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }
};
