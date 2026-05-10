class Solution {
public:
    int n;
    vector<int> dp;

    int solve(int i, vector<int>& nums, int target) {
        if (i == n - 1) return 0;

        if (dp[i] != -1) return dp[i];

        int ans = -1;

        for (int j = i + 1; j < n; j++) {
            if (abs(nums[j] - nums[i]) <= target) {
                int next = solve(j, nums, target);

                if (next != -1) {
                    ans = max(ans, 1 + next);
                }
            }
        }

        return dp[i] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        dp.assign(n, -1);

        return solve(0, nums, target);
    }
};