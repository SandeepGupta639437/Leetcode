class Solution {
public:
    int dp[102][102];

    int solve(int l, int r, vector<int>& cuts) {
        if (r-l == 1) return 0;

        if (dp[l][r] != -1) return dp[l][r];

        int ans = INT_MAX;

        for (int k = l + 1; k < r; k++) {
            ans = min(ans, (cuts[r]-cuts[l]) + solve(l, k, cuts) + solve(k, r, cuts));
        }

        return dp[l][r] = ans;
    }

    int minCost(int n, vector<int>& cuts) {

        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        memset(dp, -1, sizeof(dp));

        return solve(0, cuts.size() - 1, cuts);
    }
};