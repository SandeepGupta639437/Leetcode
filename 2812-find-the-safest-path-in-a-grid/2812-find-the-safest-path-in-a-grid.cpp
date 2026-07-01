class Solution {
public:
    typedef pair<int,int> P;

    vector<vector<int>> direction{{-1,0},{1,0},{0,-1},{0,1}};

    bool isSafe(int i,int j,int n){
        return i>=0 && j>=0 && i<n && j<n;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size();

        queue<P> que;
        vector<vector<int>> score(n, vector<int>(n, INT_MAX));

        // Multi Source BFS
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    que.push({i,j});
                    score[i][j]=0;
                }
            }
        }

        while(!que.empty()){

            auto [i,j]=que.front();
            que.pop();

            for(auto &dir:direction){

                int ni=i+dir[0];
                int nj=j+dir[1];

                if(isSafe(ni,nj,n) && score[ni][nj]==INT_MAX){

                    score[ni][nj]=min(score[ni][nj],score[i][j]+1);
                    que.push({ni,nj});
                }
            }
        }

        // Max Heap : {minimum safeness till now,{x,y}}
        priority_queue<pair<int,P>> pq;
        vector<vector<int>> vis(n,vector<int>(n,0));

        pq.push({score[0][0],{0,0}});
        vis[0][0]=1;

        while(!pq.empty()){

            auto [safe,xy]=pq.top();
            pq.pop();

            int x=xy.first;
            int y=xy.second;

            if(x==n-1 && y==n-1)
                return safe;

            for(auto &dir:direction){

                int nx=x+dir[0];
                int ny=y+dir[1];

                if(isSafe(nx,ny,n) && !vis[nx][ny]){

                    vis[nx][ny]=1;

                    int newSafe=min(safe,score[nx][ny]);

                    pq.push({newSafe,{nx,ny}});
                }
            }
        }

        return 0;
    }
};