class Solution {
public:
    int m,n;
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0'){
            // peri++;
            return ;
        }
        if(grid[i][j]=='#')return;

        grid[i][j] = '#';

        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int isLands = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    isLands++;
                }
            }
        }
        return isLands;
    }
};