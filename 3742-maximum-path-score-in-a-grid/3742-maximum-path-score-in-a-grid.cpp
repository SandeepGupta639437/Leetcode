class Solution {
public:
    int dp[201][201][201];
    int n, m;

    int solve(int i, int j, vector<vector<int>>& grid, int k, int cst) {
        if (i >= m || j >= n) return INT_MIN;

        int new_cost = cst + (grid[i][j]>0);

        if (new_cost > k) return INT_MIN;

        if (i == m-1 && j == n-1) {
            return grid[i][j];
        }

        if (dp[i][j][cst] != -1) return dp[i][j][cst];

        int right = solve(i, j+1, grid, k, new_cost);
        int down  = solve(i+1, j, grid, k, new_cost);

        int best = max(right, down);

        if(best==INT_MIN)return dp[i][j][cst] = INT_MIN;

        return dp[i][j][cst] = grid[i][j] + best;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        memset(dp, -1, sizeof(dp));

        int result =  solve(0, 0, grid, k, 0);
        if(result == INT_MIN)return -1;
        return result;
    }
};