class Solution {
public:
    
    map<pair<TreeNode*, bool>, int> dp;
    
    int solve(TreeNode* root, bool parentRobbed){
        if(!root) return 0;
        
        if(dp.count({root, parentRobbed}))
            return dp[{root, parentRobbed}];
        
        int result;
        
        if(parentRobbed){
            // Cannot rob this node
            result = solve(root->left, false) 
                   + solve(root->right, false);
        }
        else{
            // Option 1: Rob this node
            int rob = root->val 
                    + solve(root->left, true) 
                    + solve(root->right, true);

            // Option 2: Skip this node
            int skip = solve(root->left, false) 
                     + solve(root->right, false);

            result = max(rob, skip);
        }
        
        return dp[{root, parentRobbed}] = result;
    }
    
    int rob(TreeNode* root) {
        return solve(root, false);
    }
};
