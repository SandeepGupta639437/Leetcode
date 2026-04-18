class Solution {
public:
    int dp[5001][301];

    int solve(int amount, vector<int>& coins, int j) {
        if (amount == 0) return 1;
        if (j >= coins.size()) return 0;

        if (dp[amount][j] != -1) return dp[amount][j];

        int ways = 0;

        // take
        if (amount - coins[j] >= 0)
            ways += solve(amount - coins[j], coins, j);

        // skip
        ways += solve(amount, coins, j + 1);

        return dp[amount][j] = ways;
    }

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return solve(amount, coins, 0);
    }
};