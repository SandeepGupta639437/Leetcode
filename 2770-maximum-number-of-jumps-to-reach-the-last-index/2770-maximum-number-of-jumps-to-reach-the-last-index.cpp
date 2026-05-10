class Solution {
public:
    int n;
    int dp[1001][1001];

    int solve(int i, int j, vector<int>& nums, int target) {

        if (i == n - 1) return 0;

        if (j >= n) return -1e9;

        int take = -1e9, skip = -1e9;

        if(dp[i][j]!=-1)return dp[i][j];

        if (abs(nums[j] - nums[i]) <= target) {
            take = 1 + solve(j, j + 1, nums, target);
        }

        skip = solve(i, j + 1, nums, target);

        return dp[i][j] = max(take, skip);
    }

    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));

        int ans = solve(0, 1, nums, target);

        return (ans < 0) ? -1 : ans;
    }
};