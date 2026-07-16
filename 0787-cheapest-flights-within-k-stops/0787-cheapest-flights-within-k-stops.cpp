class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : flights){
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<int> dist(n, INT_MAX);

        queue<pair<int,int>> q;
        q.push({src, 0});
        dist[src] = 0;

        int stops = 0;

        while (!q.empty() && stops <= k) {

            int sz = q.size();

            while (sz--) {

                auto [node, cost] = q.front();
                q.pop();

                for (auto &[next, wt] : adj[node]) {

                    if (cost + wt < dist[next]) {
                        dist[next] = cost + wt;
                        q.push({next, cost + wt});
                    }
                }
            }
            stops++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};