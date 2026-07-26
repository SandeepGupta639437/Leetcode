class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {

        int M = r - l + 1;

        int dp[2001][2002][2];
        memset(dp, 0, sizeof(dp));

        // Base case
        for (int val = 1; val <= M; val++) {
            dp[n - 1][val][0] = 1;
            dp[n - 1][val][1] = 1;
        }

        // DP
        for (int i = n - 2; i >= 0; i--) {

            vector<long long> cumSum0(M + 1, 0);
            vector<long long> cumSum1(M + 1, 0);

            for (int val = 1; val <= M; val++) {
                cumSum0[val] = (cumSum0[val - 1] + dp[i + 1][val][0]) % MOD;
                cumSum1[val] = (cumSum1[val - 1] + dp[i + 1][val][1]) % MOD;
            }

            for (int val = 1; val <= M; val++) {
                dp[i][val][1] = (cumSum0[M] - cumSum0[val] + MOD) % MOD;
                dp[i][val][0] = cumSum1[val - 1];
            }
        }

        long long ans = 0;
        for (int val = 1; val <= M; val++) {
            ans = (ans + dp[0][val][0]) % MOD;
            ans = (ans + dp[0][val][1]) % MOD;
        }

        return ans;
    }
};