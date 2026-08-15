class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        if(n>2){
            for(int i=1;i<n-1;i++){
                xr^=nums[i];
            }
        }
        if(n==1 ){
            if(nums[0]!=0)return 1;
            return 0;
        }

        int cnt0 = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)cnt0++;
        }

        if(cnt0==n)return 0;

        if((xr^nums[0]^nums[n-1])!=0)return n;
        else return n-1;
    }
};