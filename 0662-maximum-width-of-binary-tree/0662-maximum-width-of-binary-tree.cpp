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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        queue<pair<TreeNode*, ll>> que;
        que.push({root, 0});

        int ans = 0;

        while(!que.empty()) {

            int size = que.size();

            ll first = que.front().second;
            ll last = que.back().second;

            ans = max(ans,(int)(last-first+1)); 

            while(size--) {

                TreeNode* temp = que.front().first;
                ll idx = que.front().second;

                que.pop();

                last = idx;

                if(temp->left)
                    que.push({temp->left, 2 * idx + 1});

                if(temp->right)
                    que.push({temp->right, 2 * idx + 2});
            }
        }

        return ans;
    }
};