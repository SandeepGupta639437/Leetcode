class Solution {
public:
    int pivotIndex(vector<int>& nums) {
           int n=nums.size();
           int tsum=0;
           int sum=0;
           for(int i=0;i<n;i++){
            tsum+=nums[i];
           } 
           for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum-nums[i]==tsum-sum)return i;
           } 
           return -1;
    }
};