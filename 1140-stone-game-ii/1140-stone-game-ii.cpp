class Solution {
public:
    int dp[101][101][101];
    int solve(int i, int j, vector<int>& piles, int M) {

        if (i > j)
            return 0;

        if(dp[i][j][M]!=-1)return dp[i][j][M];

        int ans = 0;
        int sum = 0;

        for (int x = 1; x <= 2 * M && i + x - 1 <= j; x++) {

            sum += piles[i + x - 1];

            // Opponent gets the best possible score
            // from the remaining piles.
            int opponent = solve(
                i + x,
                j,
                piles,
                max(M, x)
            );

            // Total stones remaining
            int total = 0;
            for (int k = i; k <= j; k++)
                total += piles[k];

            // My stones = total - opponent
            ans = max(ans, total - opponent);
        }

        return dp[i][j][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();
        memset(dp,-1,sizeof(dp));

        return solve(0, n - 1, piles, 1);
    }
};