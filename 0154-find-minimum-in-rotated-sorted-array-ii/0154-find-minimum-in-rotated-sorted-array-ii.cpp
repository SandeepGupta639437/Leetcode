class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int a=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]<a){
                a=nums[i];
            }
        }
        return a;
    }
};