class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double ans=INT_MAX;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        while(i<j){
           ans=min(ans,(nums[i]+nums[j])/2.0);
           i++;
           j--;
        }
        return ans;
    }
};