class Solution {
public:
    TreeNode* solve(int &idx, vector<int>& inorder, vector<int>& postorder, int start, int end) {

        if(start > end) return NULL;

        int rootVal = postorder[idx];

        int i = start;

        for(; i <= end; i++) {
            if(inorder[i] == rootVal) break;
        }
        idx++;

        TreeNode* root = new TreeNode(rootVal);

        // RIGHT first because reversed postorder = Root -> Right -> Left
        root->right = solve(idx, inorder, postorder, i + 1, end);
        root->left = solve(idx, inorder, postorder, start, i - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        reverse(postorder.begin(), postorder.end());

        int idx = 0;

        return solve(idx, inorder, postorder, 0, postorder.size() - 1);
    }
};