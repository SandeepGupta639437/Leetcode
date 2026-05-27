class Solution {
public:
    int m,n ;
    int dp[201][201];
    int solve(vector<vector<int>>& grid,int i, int j){
        if(i==m-1 && j==n-1)return grid[i][j];
        if(i>=m || j>=n)return INT_MAX;

        if(dp[i][j]!=-1)return dp[i][j];

        int bottom = solve(grid,i+1,j);
        int right = solve(grid,i,j+1);
        int ans = min(bottom,right);

        if(ans == INT_MAX)
            return INT_MAX;

        return dp[i][j] = grid[i][j] + ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0);
    }
};