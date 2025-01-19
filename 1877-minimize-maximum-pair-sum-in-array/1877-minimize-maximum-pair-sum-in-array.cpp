class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long maxi=INT_MIN;
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum=nums[i]+nums[n-i-1];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};