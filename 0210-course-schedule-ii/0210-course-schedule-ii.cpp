class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int u, vector<int>& vis, stack<int>& st) {
        vis[u] = 1; // visiting

        for (int v : adj[u]) {
            if (vis[v] == 1)
                return false; // cycle

            if (vis[v] == 0) {
                if (!dfs(adj, v, vis, st))
                    return false;
            }
        }

        vis[u] = 2; // visited
        st.push(u);
        return true;
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);

        for (auto &it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                if (!dfs(adj, i, vis, st))
                    return {};
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};