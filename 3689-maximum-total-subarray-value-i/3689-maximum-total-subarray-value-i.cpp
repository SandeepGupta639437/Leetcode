class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = nums[0],maxi = nums[0];
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
            mini = min(mini,nums[i]);
        }
        int ans = maxi-mini;
        return 1LL*ans*k;
    }
};