class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size(),inc=1,dec=1,flag1=0,flag2=0,ans1=1,ans2=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                inc++;
                ans1=max(ans1,inc);
                flag1=1;
            }
            else if(nums[i]>nums[i+1]){
                dec++;
                ans2=max(ans2,dec);
                flag2=1;
            }
            if(flag1==0)inc=0;
            if(flag2==0)dec=0;
        }
        return max(ans1,ans2);
    }
};