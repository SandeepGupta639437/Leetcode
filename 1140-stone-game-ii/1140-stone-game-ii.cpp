class Solution {
public:
    int dp[101][101];
    int n;
    int solve(int i, vector<int>& piles, int M) {

        if (i > n) return 0;

        if(dp[i][M]!=-1)return dp[i][M];

        int ans = 0;
        int sum = 0;

        for (int x = 1; x <= 2 * M && i + x - 1 <= n; x++) {

            sum += piles[i + x - 1];

            int opponent = solve( i + x, piles, max(M, x) );

            // Total stones remaining
            int total = 0;
            for (int k = i; k <= n; k++) total += piles[k];

            // My stones = total - opponent
            ans = max(ans, total - opponent);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size()-1;
        memset(dp,-1,sizeof(dp));

        return solve(0, piles, 1);
    }
};