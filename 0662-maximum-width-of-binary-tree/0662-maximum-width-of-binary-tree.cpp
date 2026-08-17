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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        queue<pair<TreeNode*, unsigned long long>> que;
        que.push({root, 0});

        int ans = 0;

        while(!que.empty()) {

            int size = que.size();

            unsigned long long first = que.front().second;
            unsigned long long last = first;

            for(int i = 0; i < size; i++) {

                TreeNode* temp = que.front().first;
                unsigned long long idx = que.front().second;

                que.pop();

                // Normalize index
                idx = idx - first;

                last = idx;

                if(temp->left)
                    que.push({temp->left, 2 * idx + 1});

                if(temp->right)
                    que.push({temp->right, 2 * idx + 2});
            }

            ans = max(ans, (int)(last + 1));
        }

        return ans;
    }
};