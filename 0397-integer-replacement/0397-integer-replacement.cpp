class Solution {
public:
    unordered_map<long long, int> dp;

    int solve(long long n) {
        if(n == 1)return 0;

        if(dp.count(n)) return dp[n];

        int result = INT_MAX;

        if(n % 2 == 0) {
            result = 1 + solve(n / 2);
        }
        else {
             result = min( 1 + solve(n - 1), 1 + solve(n + 1));
        }

        return dp[n] = result;
    }

    int integerReplacement(int n) {
        return solve(n);
    }
};