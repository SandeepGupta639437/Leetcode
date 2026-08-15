class Solution {
public:
    int n;
    int dp[51][5];

    int solve(int i, int prev) {
        if(i == n) return 1;

        if(dp[i][prev] != -1)  return dp[i][prev];

        int ans = 0;

        for(int j = prev; j < 5; j++) {
            ans += solve(i + 1, j);
        }

        return dp[i][prev] = ans;
    }

    int countVowelStrings(int N) {
        n = N;
        memset(dp, -1, sizeof(dp));

        return solve(0, 0);
    }
};