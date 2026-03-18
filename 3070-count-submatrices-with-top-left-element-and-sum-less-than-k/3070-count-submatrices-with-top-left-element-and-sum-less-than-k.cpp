class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
             if(j>0)grid[i][j]+=grid[i][j-1];
             if(i>0)grid[i][j]+=grid[i-1][j];
            //  if(i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];
           }
        }
        int ans=0;
        for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
             if(grid[i][j]<=k)ans++;
           }
        }
        return ans;
    }
};