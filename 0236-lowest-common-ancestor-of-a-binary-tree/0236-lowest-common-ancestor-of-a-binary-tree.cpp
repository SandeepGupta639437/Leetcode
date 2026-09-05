/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> ancestorTable;
    vector<int> depth;
    vector<TreeNode*> nodeFromId;
    unordered_map<TreeNode*, int> id;

    int rows, cols;

    // Assign every node an index
    void assignId(TreeNode* root) {
        if (!root) return;

        id[root] = nodeFromId.size();
        nodeFromId.push_back(root);

        assignId(root->left);
        assignId(root->right);
    }

    // Build parent array and depth array
    void dfs(TreeNode* node, TreeNode* par, vector<int>& parent, int d) {
        if (!node) return;

        int idx = id[node];

        if (par == nullptr)
            parent[idx] = -1;
        else
            parent[idx] = id[par];

        depth[idx] = d;

        dfs(node->left, node, parent, d + 1);
        dfs(node->right, node, parent, d + 1);
    }

    void buildAncestorTable(int n, vector<int>& parent) {
        rows = n;
        cols = log2(n) + 1;

        ancestorTable.assign(rows, vector<int>(cols, -1));

        for (int i = 0; i < n; i++)
            ancestorTable[i][0] = parent[i];

        for (int j = 1; j < cols; j++) {
            for (int i = 0; i < n; i++) {
                if (ancestorTable[i][j - 1] != -1) ancestorTable[i][j] = ancestorTable[ancestorTable[i][j - 1]][j - 1];
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < cols; j++) {
            if (node == -1) return -1;

            if (k & (1 << j)) {
                node = ancestorTable[node][j];
            }
        }
        return node;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Step 1 : Number every node
        assignId(root);

        int n = nodeFromId.size();

        vector<int> parent(n, -1);
        depth.resize(n);

        // Step 2 : Build parent and depth
        dfs(root, nullptr, parent, 0);

        // Step 3 : Binary lifting table
        buildAncestorTable(n, parent);

        int u = id[p];
        int v = id[q];

        // Step 4 : Bring to same depth
        if (depth[u] > depth[v]){
            u = getKthAncestor(u, depth[u] - depth[v]);
        }
        else{
            v = getKthAncestor(v, depth[v] - depth[u]);
        }

        if (u == v) return nodeFromId[u];

        // Step 5 : Lift together
        for (int j = cols - 1; j >= 0; j--) {
            if (ancestorTable[u][j] != -1 && ancestorTable[v][j] != -1 && ancestorTable[u][j] != ancestorTable[v][j]) {
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return nodeFromId[parent[u]];
    }
};