class Solution {
public:
    int m, n;
    int dp[101][101][201];
    bool solve(int i,int j,vector<vector<char>>& grid,int sum){
        if(i>=m || i<0 || j>=n || j<0)return false;

        if(grid[i][j]=='(')sum++;
        else sum--;

        if(sum < 0) return false;

        if(dp[i][j][sum]!=-1)return dp[i][j][sum];

        if(i==m-1 && j==n-1)return (sum==0);

        return dp[i][j][sum] = (solve(i+1,j,grid,sum) || solve(i,j+1,grid,sum));
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid,0);
    }
};