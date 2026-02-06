class Solution {
    int dp[] = new int[46];

    int solve(int n) {
        if (n == 1) return 1;
        if (n == 0) return 1;   // Important: ways to stay at 0 = 1

        if (dp[n] != 0) return dp[n];   // memo check

        return dp[n] = solve(n - 1) + solve(n - 2);
    }

    public int climbStairs(int n) {
        return solve(n);
    }
}
