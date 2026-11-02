class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();

        int x = nums[(n+1)/2-1];
        for(int i=0;i<n;i++){
            ans += abs(x-nums[i]);
        }
        return ans;
    }
};