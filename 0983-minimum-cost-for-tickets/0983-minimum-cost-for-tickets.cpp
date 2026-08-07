class Solution {
public:
    int n;
    int dp[366][366];

    int solve(int i, vector<int>& days, vector<int>& costs, int x) {
        if (i >= n) return 0;

        x = days[i];

        if(dp[i][x] !=-1)return dp[i][x];

        int idx1 = lower_bound(days.begin(), days.end(), x + 1) - days.begin();
        int idx2 = lower_bound(days.begin(), days.end(), x + 7) - days.begin();
        int idx3 = lower_bound(days.begin(), days.end(), x + 30) - days.begin();

        return dp[i][x] = min({
            costs[0] + solve(idx1, days, costs, x + 1),
            costs[1] + solve(idx2, days, costs, x + 7),
            costs[2] + solve(idx3, days, costs, x + 30)
        });
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        memset(dp,-1,sizeof(dp));
        return solve(0, days, costs, days[0]);
    }
};