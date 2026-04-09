class Solution {
public:
    using ll = long long;
    const ll MOD = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        for(auto it:queries){
            int idx = it[0];
            while(idx<=it[1]){
                nums[idx] = (1LL*nums[idx]*it[3])%MOD;
                idx+=it[2];
            }
        }
        int ans =0;
        for(auto it:nums){
            ans^=it;
        }
        return ans;
        
    }
};