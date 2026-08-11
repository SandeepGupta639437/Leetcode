class Solution {
public:
    int n, m, maxMoves;
    int dp[51][51][55];
    const int MOD = 1e9 + 7;

    int solve(int row, int col, int moves) {

        if(moves > maxMoves) return 0;

        if(row >= m || col >= n || row < 0 || col < 0) return 1;

        if(dp[row][col][moves] != -1) return dp[row][col][moves];

        int ans = 0;

        ans = (ans + solve(row + 1, col, moves + 1)) % MOD;
        ans = (ans + solve(row - 1, col, moves + 1)) % MOD;
        ans = (ans + solve(row, col + 1, moves + 1)) % MOD;
        ans = (ans + solve(row, col - 1, moves + 1)) % MOD;

        return dp[row][col][moves] = ans;
    }

    int findPaths(int M, int N, int MaxMove, int startRow, int startColumn) {

        n = N;
        m = M;
        maxMoves = MaxMove;

        memset(dp, -1, sizeof(dp));

        return solve(startRow, startColumn, 0);
    }
};