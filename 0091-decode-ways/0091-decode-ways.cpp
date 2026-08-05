class Solution {
public:
    int n;
    int dp[101];

    int solve(int i, string &s) {
        if (i == n) return 1;

        if(dp[i]!=-1)return dp[i];

        if (s[i] == '0') return 0;

        int ways = solve(i + 1, s);

        if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            ways += solve(i + 2, s);
        }

        return dp[i] = ways;
    }

    int numDecodings(string s) {
        n = s.size();
        memset(dp,-1,sizeof(dp));
        return solve(0, s);
    }
};