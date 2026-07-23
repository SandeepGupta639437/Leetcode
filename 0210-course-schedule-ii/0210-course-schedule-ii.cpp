class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Build graph and indegree
        for (auto &it : prerequisites) {
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        // Push all nodes with indegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            ans.push_back(u);

            for (int v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        // If all courses are processed, return the order
        if (ans.size() == n)
            return ans;

        // Cycle exists
        return {};
    }
};