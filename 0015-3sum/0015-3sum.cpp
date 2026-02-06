class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
                  int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>result;
        for(int i=0;i<n-2;i++){
            int left=i+1;
            int right=n-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==0){
                    result.insert({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                }else if(sum<0){
                    left++;

                }else{
                    right--;
                }
            }
            
        }
        vector<vector<int>> resultVector(result.begin(), result.end());
        return resultVector;
        
   }
};