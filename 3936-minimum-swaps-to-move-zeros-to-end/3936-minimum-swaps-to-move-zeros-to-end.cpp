class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0;
        for(auto i:nums){
            if(i==0)cnt0++;
        }
        int ans = 0;
        int j = 0;
        int i = n-1;
        while(j<cnt0){
            if(nums[i]!=0)ans++;
            i--;
            j++;
        }
        return ans;
    }
};