// BELLMANFORD ALGO

class Solution {
public:
    typedef pair<int,int> P;

    void bellmanFord(int n , vector<vector<int>> &edges, vector<int> &result, int S){
        fill(begin(result),end(result),INT_MAX);

        result[S] = 0;

        while(n--){
            for(auto &edge: edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if(result[u]!= INT_MAX && result[u]+ wt < result[v]){
                    result[v] = result[u]+wt;
                }
                if(result[v]!= INT_MAX && result[v]+ wt < result[u]){
                    result[u] = result[v]+wt;
                }
            }
        }

    }


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> SPM(n,vector<int>(n,INT_MAX));

        for(int i=0;i<n;i++){
            SPM[i][i] = 0;
        }

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            int distance = edge[2];
            
            SPM[u][v] = distance;
            SPM[v][u] = distance;
        }

        for(int i=0;i<n;i++){
            bellmanFord(n,edges,SPM[i],i);
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