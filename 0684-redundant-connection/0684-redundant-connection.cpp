class Solution {
public:

 bool bfs(unordered_map<int, vector<int>>& adj, int u, int v) {
    queue<int> que;
    unordered_set<int> vis;
    que.push(u);
    vis.insert(u);

    while (!que.empty()) {
        int node = que.front();
        que.pop();
        if (node == v) return true; // found target
        for (auto nei : adj[node]) {
            if (!vis.count(nei)) {
                vis.insert(nei);
                que.push(nei);
            }
        }
    }
    return false; // no path found
}

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int,vector<int>>adj;

        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(adj.find(u)!=adj.end() && adj.find(v)!=adj.end() && bfs(adj,u,v)){
                return edges[i];
            }else{
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        return {};
    }
};