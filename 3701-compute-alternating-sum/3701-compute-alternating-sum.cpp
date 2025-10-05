class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i+=2){
            sum+=nums[i];
        }
        for(int i=1;i<n;i+=2){
            sum-=nums[i];
        }
        return sum;
        
    }
};