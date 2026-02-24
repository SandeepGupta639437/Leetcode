class Solution {
public:
    int ans = 0;

    void solve(TreeNode* root, int current) {
        if (root == NULL)
            return;

        // build binary number
        current = (current << 1) | root->val;

        // if leaf node
        if (root->left == NULL && root->right == NULL) {
            ans += current;
            return;
        }
        solve(root->left, current);
        solve(root->right, current);
    }

    int sumRootToLeaf(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};