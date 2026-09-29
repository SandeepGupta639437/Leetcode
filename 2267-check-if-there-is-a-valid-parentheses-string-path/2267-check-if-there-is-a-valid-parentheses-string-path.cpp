class Solution {
public:
    int m, n;
    int dp[101][101][201];

    bool solve(int i, int j, int sum, vector<vector<char>>& grid) {

        sum += (grid[i][j]=='(')?1:-1;

        if(sum < 0) return false;

        if(dp[i][j][sum] != -1) {
            return dp[i][j][sum];
        }
        
        if(i==m-1 && j==n-1) return dp[i][j][sum] = (sum == 0);

        if(i+1 < m) {
            if(solve(i+1,j,sum,grid))  return dp[i][j][sum] = true;
        }

        if(j+1 < n) {
            if(solve(i,j+1,sum,grid)) return dp[i][j][sum] = true;
        }

        return dp[i][j][sum] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
    
        if(grid[0][0] == ')') return false;

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0, grid);
    }
};