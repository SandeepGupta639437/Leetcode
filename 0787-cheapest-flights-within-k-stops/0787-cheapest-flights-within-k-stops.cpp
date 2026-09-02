class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<vector<int>> q;
        q.push({0, src, 0});
        vector<int> dis(n, INT_MAX);
        dis[src] = 0;
        while (!q.empty()) {
            auto x = q.front();
            int stops = x[0];
            int node  = x[1];
            int cost  = x[2];
            q.pop();

            if (stops > k) continue;

            for (auto& it : adj[node]) {
                int next = it.first;
                int price = it.second;

                int newCost = cost + price;
                if (newCost < dis[next]) {
                    dis[next] = newCost;
                    q.push({stops + 1, next, newCost});
                }
            }
        }
        if (dis[dst] == INT_MAX) return -1;

        return dis[dst];
    }
};