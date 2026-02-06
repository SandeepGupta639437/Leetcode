class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=0,ans=0;
        int n=nums.size();
        while(j<n){
            if(1LL * nums[i] * k >= nums[j] ){
                j++;
                ans=max(ans,j-i+1);
            }
            else{
                i++;
            }
        }
        return n-ans+1;
        
    }
};