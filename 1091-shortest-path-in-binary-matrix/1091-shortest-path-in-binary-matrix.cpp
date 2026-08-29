class Solution {
public:
    int n;
    vector<vector<int>>direction{{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,-1},{-1,1},{1,-1}};

    bool isSafe(int i,int j,int n,int m,vector<vector<int>>& grid){
        if(i>=0 && j>=0 && i<m && j<n )return true;
        return false;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<pair<int,int>>que;

        int ans = 1;

        que.push({0,0});

        while(!que.empty()){
            int sz = que.size();

            bool flag = true;

            while(sz--){
                auto [x,y] = que.front();
                que.pop();

                visited[x][y] = true;

                if(x==n-1 && y==n-1){
                    return ans;
                }

                for (auto &d : direction) {
                    int new_i = x + d[0];
                    int new_j = y + d[1];

                    if(isSafe(new_i,new_j,n,n,grid)){
                        if(visited[new_i][new_j]==true)continue;
                        if (grid[new_i][new_j] == 1) continue;
                        visited[new_i][new_j] = true;
                        que.push({new_i,new_j});
                    }
                }
            }
            ans++;
        }
        return -1;  
    }
};