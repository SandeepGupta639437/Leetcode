class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
               for(int j=0;j<n;j++){
                    if(nums[j]==2){
                        ans = min(ans,abs(i-j));
                    }
                }
            }
            if(nums[i]==2){
               for(int j=0;j<n;j++){
                    if(nums[j]==1){
                        ans = min(ans,abs(i-j));
                    }
                }
            }
        }
        if(ans>100)return -1;
        return ans;
    }
};