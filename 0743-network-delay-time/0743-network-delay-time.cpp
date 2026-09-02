class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto &v : times){
            adj[v[0]].push_back({v[1],v[2]});
        }

        queue<pair<int,int>> que;

        vector<int> timeTaken(n+1,INT_MAX);
        que.push({0,k});
        timeTaken[k] = 0;

        while(!que.empty()){
            auto x = que.front();
            que.pop();

            int timeT = x.first;
            int node = x.second;

            for(auto &v : adj[node]){
                int nextNode = v.first;
                int nextTime = timeT + v.second;

                if(nextTime < timeTaken[nextNode]){
                    timeTaken[nextNode] = nextTime;
                    que.push({nextTime,nextNode});
                }
            }
        }

        int ans = *max_element(timeTaken.begin()+1,timeTaken.end());

        if(ans == INT_MAX)return -1;

        return ans;
    }
};