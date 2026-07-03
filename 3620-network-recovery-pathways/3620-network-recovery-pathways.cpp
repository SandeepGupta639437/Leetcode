class Solution {
    long long LIMIT = 1e14;   // Safe "infinity" to prevent overflow
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> graph(n);
        int left = INT_MAX, right = INT_MIN;
        
        // Build graph with only online nodes and track weight range
        for (vector<int>& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (online[u] && online[v]) {
                graph[u].emplace_back(v, w);
                right = max(right, w);
                left = min(left, w);
            }
        }
        
        // If no edges, early return handled naturally by binary search
        
        auto canReach = [&](int threshold) -> bool {
            vector<long long> dist(n, LIMIT);
            dist[0] = 0;
            
            // Min-heap: {current_cost, node}
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
            pq.emplace(0, 0);

            while (!pq.empty()) {
                auto [cost, u] = pq.top(); 
                pq.pop();
                
                // Skip outdated entries
                if (cost > dist[u]) continue;
                
                // Early exit: we found a valid path
                if (u == n - 1) {
                    return cost <= k;
                }

                for (auto& [v, w] : graph[u]) {
                    if (w < threshold) continue;  // Violates bottleneck
                    
                    long long newCost = cost + w;
                    if (newCost < dist[v]) {
                        dist[v] = newCost;
                        pq.emplace(newCost, v);
                    }
                }
            }
            return false;
        };

        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canReach(mid)) {
                ans = mid;        // Try for better (larger) bottleneck
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};