// DIJKSTRA ALGO

class Solution {
public:
    typedef pair<int,int> P;

    void dijkshtra(int n , vector<vector<P>> &adj, vector<int> &result, int S){
        priority_queue< P,vector<P> , greater<P> > pq;
        pq.push({0,S}); // distance , node

        fill(result.begin(),result.end(),INT_MAX);

        while(!pq.empty()){
            auto x = pq.top();
            int d = x.first;
            int node = x.second;
            pq.pop();

            for(auto& p: adj[node]){
                int adjNode = p.first;
                int dist = p.second;

                if(d + dist < result[adjNode]){
                    result[adjNode] = d + dist;
                    pq.push({d+dist, adjNode});
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> SPM(n,vector<int>(n,INT_MAX));

        for(int i=0;i<n;i++){
            SPM[i][i] = 0;
        }

        vector<vector<P>> adj(n);

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            int distance = edge[2];
            
            adj[u].push_back({v,distance});
            adj[v].push_back({u,distance});
        }

        for(int i=0;i<n;i++){
            dijkshtra(n,adj,SPM[i],i);
        }

        int ans = 0;
        int maxCnt = n;

        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(i!=j && SPM[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=maxCnt){
                maxCnt = cnt;
                ans = i;
            }
        }

        return ans;
    }
};