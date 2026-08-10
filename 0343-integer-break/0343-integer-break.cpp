class Solution {
public:
    int dp[60];
    int solve(int n) {
        if(n == 1) return 1;

        int result = 0;
        if(dp[n]!=-1)return dp[n];

        for(int i = 1; i < n; i++) {
            result = max(result, i * solve(n - i));
            result = max(result, i * (n - i));
        }

        return dp[n] = result;
    }

    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};