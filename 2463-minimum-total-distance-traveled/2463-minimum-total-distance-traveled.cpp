class Solution {
public:
    using ll = long long;
    ll dp[101][101];
    int n,m;

    ll solve(int i, int j, vector<int>& robot, vector<vector<int>>& factory) {
        // All robots assigned
        if (i == n) return 0;

        // No factories left
        if (j == m) return 1e15;

        if (dp[i][j] != -1) return dp[i][j];

        ll ans = solve(i, j + 1, robot, factory); // skip factory

        ll dist = 0;
        int pos = factory[j][0];
        int cap = factory[j][1];

        // Try assigning k robots to this factory
        for (int k = 0; k < cap && i + k < robot.size(); k++) {
            dist += abs(robot[i + k] - pos);
            ans = min(ans, dist + solve(i + k + 1, j + 1, robot, factory));
        }

        return dp[i][j] = ans;
    }

    ll minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        n = robot.size();
        m = factory.size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, robot, factory);
    }
};