class Solution {
public:
    typedef pair<int,int> P;

    bool isSafe(int i,int j,int n,int m,vector<vector<int>>& grid){
        if(i>=0 && j>=0 && i<m && j<n && grid[i][j]==1)return true;
        return false;
    }

    vector<vector<int>>direction{{-1,0},{1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<P>que;  // it will store the quards of cell
        int freshCount  = 0;

        for(int i=0;i<m;i++){

            for(int j = 0; j<n ;j++){
                if(grid[i][j] == 2){
                    que.push({i,j});
                }else if(grid[i][j]==1){
                    freshCount++;
                }
            }
        }

        if(freshCount == 0)return 0; //all oranges are rotten;

        int minutes = 0;

        while(!que.empty()){
           int siz = que.size();
           while(siz--){
              P curr = que.front();
              que.pop();

              int i = curr.first;
              int j = curr.second;

              for(vector<int>&dir : direction){
                int new_i = i+dir[0];
                int new_j = j+dir[1];

                if(isSafe(new_i,new_j,n,m,grid)){
                    grid[new_i][new_j] = 2;
                    que.push({new_i,new_j});
                    freshCount--;
                }
              }
           }
           minutes++;
        }
      return freshCount == 0 ? (minutes-1) : -1;
    }
};