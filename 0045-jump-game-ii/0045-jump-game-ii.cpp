class Solution {
public:
    int dp[10001];
    int n;

    int solve(int idx, vector<int>& nums) {
        if (idx == n - 1) return 0;

        if (dp[idx] != -1) return dp[idx];

        int ans = INT_MAX;

        for (int i = idx+1; i<=min(n-1, idx+nums[idx]); i++) {
            int next = solve(i,nums);
            if (next != INT_MAX) ans = min(ans,1+next);
        }

        return dp[idx] = ans;
    }

    int jump(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, nums);
    }
};