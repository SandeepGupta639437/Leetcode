class Solution {
public:
    int dp[201][201];
    const int INF = 1e9;

    int solve(int i, int j, vector<vector<int>>& triangle) {
        if (i == triangle.size()) return 0;

        if (dp[i][j] != INF) return dp[i][j];

        return dp[i][j] = triangle[i][j] + min(solve(i + 1, j, triangle), solve(i + 1, j + 1, triangle));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        fill(&dp[0][0], &dp[0][0] + 201 * 201, INF);
        return solve(0, 0, triangle);
    }
};