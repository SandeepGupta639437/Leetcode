class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector f(n + 1, vector<int>(3, INT_MIN));
        for(int k = 0; k < 3; k++){
            f[1][k] = 0;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int x = coins[i][j];
                f[j + 1][2] = max(max(f[j + 1][2], f[j][2]) + x, max(f[j + 1][1], f[j][1]));
                f[j + 1][1] = max(max(f[j + 1][1], f[j][1]) + x, max(f[j + 1][0], f[j][0]));
                f[j + 1][0] = max(f[j + 1][0], f[j][0]) + x;
            }
        }
        return f[n][2];
    }
    // time complexity: O(mn)
    // space complexity: O(n)
};