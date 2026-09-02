// FLOYEDWARSHALL ALGO

class Solution {
public:
    typedef pair<int,int> P;

    void floyedWarshall(int n,vector<vector<int>> &SPM ){
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(SPM[i][via] != INT_MAX && SPM[via][j] != INT_MAX) {
                        SPM[i][j] = min(SPM[i][j], SPM[i][via] + SPM[via][j]);
                    }
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

        // for(int i=0;i<n;i++){
        //     bellmanFord(n,edges,SPM[i],i);
        // }

        floyedWarshall(n,SPM);

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