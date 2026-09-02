class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto &v : flights){
            adj[v[0]].push_back({v[1],v[2]});
        }

        queue< pair<int,pair<int,int>> >que;
        que.push({0,{src,0}}); // stopstaken , node(from) , cost

        vector<int>dist(n,INT_MAX);
        dist[src] = 0;

        while(!que.empty()){
            auto x = que.front();
            int stops = x.first;
            int node = x.second.first;
            int cost = x.second.second;

            que.pop();

            if(stops > k)continue;

            for(auto &v : adj[node]){
                int nextNode = v.first;
                int nextCost = cost + v.second;

                if(nextCost < dist[nextNode]){
                    dist[nextNode] = nextCost;
                    que.push({stops+1,{nextNode,nextCost}});
                }
            }
        }
        if(dist[dst] == INT_MAX)return -1;

        return dist[dst];
    }
};