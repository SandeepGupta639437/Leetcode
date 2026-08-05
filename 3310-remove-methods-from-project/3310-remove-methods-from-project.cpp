class Solution {
public:
    vector<bool> vis;

    void dfs(int u, const vector<vector<int>>& graph) {
        vis[u] = true;
        for (int v : graph[u]) {
            if (!vis[v])
                dfs(v, graph);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        for (auto &e : invocations)
            graph[e[0]].push_back(e[1]);

        vis.assign(n, false);
        dfs(k, graph);

        // If an outside method invokes a suspicious method,
        // nothing can be removed.
        for (auto &e : invocations) {
            if (!vis[e[0]] && vis[e[1]]) {
                vector<int> ans(n);
                iota(ans.begin(), ans.end(), 0);
                return ans;
            }
        }

        vector<int> ans;
        ans.reserve(n);

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};