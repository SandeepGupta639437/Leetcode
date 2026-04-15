class Solution {
public:
    long long dp[101][101];

    long long solve(int i, int j, vector<int>& robot, vector<vector<int>>& factory) {
        // All robots assigned
        if (i == robot.size()) return 0;

        // No factories left
        if (j == factory.size()) return 1e15;

        if (dp[i][j] != -1) return dp[i][j];

        long long ans = solve(i, j + 1, robot, factory); // skip factory

        long long dist = 0;
        int pos = factory[j][0];
        int cap = factory[j][1];

        // Try assigning k robots to this factory
        for (int k = 0; k < cap && i + k < robot.size(); k++) {
            dist += abs(robot[i + k] - pos);
            ans = min(ans, dist + solve(i + k + 1, j + 1, robot, factory));
        }

        return dp[i][j] = ans;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, robot, factory);
    }
};