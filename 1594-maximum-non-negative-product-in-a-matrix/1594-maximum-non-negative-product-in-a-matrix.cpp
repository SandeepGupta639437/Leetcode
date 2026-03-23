class Solution {
public:
    using ll = long long;
    pair<ll,ll> dp[16][16];
    bool vis[16][16];
    int MOD = 1e9+7;

    pair<ll,ll> solve(int i,int j,vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();

        if(i>=n||j>=m) return {LLONG_MIN, LLONG_MAX};

        if(i==n-1&&j==m-1) return {grid[i][j], grid[i][j]};

        if(vis[i][j]) return dp[i][j];
        vis[i][j] = true;

        auto down = solve(i+1, j, grid);
        auto right = solve(i, j+1, grid);

        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

        // from down
        if(down.first != LLONG_MIN){
            long long a = grid[i][j] * down.first;
            long long b = grid[i][j] * down.second;
            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        // from right
        if(right.first != LLONG_MIN){
            long long a = grid[i][j] * right.first;
            long long b = grid[i][j] * right.second;
            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        return dp[i][j] = {maxi, mini};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        memset(vis, false, sizeof(vis));

        auto res = solve(0,0,grid);

        if(res.first < 0) return -1;
        return res.first % MOD;
    }
};