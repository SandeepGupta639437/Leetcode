using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        // dp[i][j][k] = max coins from (i,j) with k neutralizations left
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -1e9)));

        // Base case (destination)
        for (int k = 0; k <= 2; k++) {
            if (coins[m-1][n-1] < 0 && k > 0)
                dp[m-1][n-1][k] = 0;
            else
                dp[m-1][n-1][k] = coins[m-1][n-1];
        }

        // Fill from bottom-right → top-left
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m-1 && j == n-1) continue;

                for (int k = 0; k <= 2; k++) {
                    int down = (i+1 < m) ? dp[i+1][j][k] : -1e9;
                    int right = (j+1 < n) ? dp[i][j+1][k] : -1e9;

                    int best = -1e9;

                    if (coins[i][j] >= 0) {
                        best = coins[i][j] + max(down, right);
                    } else {
                        // neutralize
                        if (k > 0) {
                            int downN = (i+1 < m) ? dp[i+1][j][k-1] : -1e9;
                            int rightN = (j+1 < n) ? dp[i][j+1][k-1] : -1e9;
                            best = max(downN, rightN);
                        }
                        // take negative
                        best = max(best, coins[i][j] + max(down, right));
                    }

                    dp[i][j][k] = best;
                }
            }
        }

        return dp[0][0][2];
    }
};