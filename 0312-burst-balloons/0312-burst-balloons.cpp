class Solution {
public:
    int dp[301][301];
    int solve(int l, int r, vector<int>& nums) {

        if (l > r) return 0;

        int ans = 0;
        if(dp[l][r]!=-1)return dp[l][r];

        for (int k = l; k <= r; k++) {
            int coins = nums[l - 1] * nums[k] * nums[r + 1] + solve(l, k - 1, nums) + solve(k + 1, r, nums);

            ans = max(ans, coins);
        }

        return dp[l][r] = ans;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memset(dp,-1,sizeof(dp));

        return solve(1, nums.size() - 2, nums); // 1-> index of first element previously // nums.size()-2 is the index of last elemnt previously
    }
};