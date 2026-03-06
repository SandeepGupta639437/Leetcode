class Solution {
public:
    typedef pair<int,int>P;

    vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};

    bool isSafe(int i, int j,int n,int m){
        if(i>=m || i<0 || j<0 || j>=n)return false;
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<P>que;
        int fresh = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j ++){
               if(grid[i][j]==2){
                que.push({i,j});
               }
               else if(grid[i][j]==1)fresh++;
            }
        }
        if(!fresh)return 0;

        int minutes=0;

        while(!que.empty()){
            int size = que.size();
            while(size--){
                P curr = que.front();
                que.pop();

                int i = curr.first;
                int j = curr.second;

                for(auto dir : directions){
                    int new_i = i+dir[0];
                    int new_j = j+dir[1];

                    if(isSafe(new_i,new_j,n,m) && grid[new_i][new_j]==1){
                        grid[new_i][new_j]=2;
                        que.push({new_i,new_j});
                        fresh--;
                    }
                }
            }
            minutes++;
        }
        if(!fresh)return minutes-1;
        return -1;
    }
};