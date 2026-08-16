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
    int maxSum = 0;
    int solve(TreeNode* root){
        if(root==NULL)return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int dono_accha_hai = l+r+root->val;

        int koi_ek_hi_accha_hai = max(l,r) + root->val;

        int sirf_root_accha_hai = root->val;

        maxSum = max({ maxSum , dono_accha_hai , koi_ek_hi_accha_hai , sirf_root_accha_hai });

        return max(koi_ek_hi_accha_hai,sirf_root_accha_hai);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};