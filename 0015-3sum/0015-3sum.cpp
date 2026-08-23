class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        int n=nums.size();

        if(n<3)return {};

        sort(nums.begin(),nums.end());

        for(int i=0;i<n-1;i++){
            if (i>0 && nums[i] == nums[i-1]) continue; // to remove duplicacy

            for(int j = i+1;j<n;j++){
                 if (j>i+1 && nums[j] == nums[j-1]) continue; // to remove duplicasy

                int target = -1*(nums[i]+nums[j]);
                int l = j + 1, r = n - 1;

                while(l<=r){
                    int mid = (l+r)/2;
                    if(nums[mid]==target){
                        result.push_back({nums[i],nums[j],nums[mid]});
                        break;
                    }else if(nums[mid]>target){
                        r = mid -1;
                    }else{
                        l = mid+1;
                    }
                }

            }
        }
        return result;
   }
};