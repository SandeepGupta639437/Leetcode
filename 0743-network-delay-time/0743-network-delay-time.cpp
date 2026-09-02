class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &v : times) {
            adj[v[0]].push_back({v[1], v[2]});
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if(time > dist[node])
                continue;

            for(auto &[nextNode, edgeTime] : adj[node]) {
                int nextTime = time + edgeTime;

                if(nextTime < dist[nextNode]) {
                    dist[nextNode] = nextTime;
                    pq.push({nextTime, nextNode});
                }
            }
        }

        int ans = *max_element(dist.begin() + 1, dist.end());

        return ans == INT_MAX ? -1 : ans;
    }
};