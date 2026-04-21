class Solution {
public:
    const int INF = 1e9;

    int dijkstra(int source, vector<vector<int>>& times, int n){
        
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &t : times){
            int u = t[0], v = t[1], w = t[2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n+1, INF);
        set<pair<int,int>> st;

        dist[source] = 0;
        st.insert({0, source});

        while(!st.empty()){
            auto [d, v] = *st.begin();
            st.erase(st.begin());

            for(auto &child : adj[v]){
                int child_v = child.first;
                int wt = child.second;

                if(d + wt < dist[child_v]){
                    dist[child_v] = d + wt;
                    st.insert({dist[child_v], child_v});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INF) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        return dijkstra(k, times, n);
    }
};