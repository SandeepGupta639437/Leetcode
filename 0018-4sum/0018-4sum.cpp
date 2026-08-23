class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>result;
        int n=nums.size();

        if(n<4)return {};

        sort(nums.begin(),nums.end());

        for(int i=0;i<n-1;i++){
            if (i>0 && nums[i] == nums[i-1]) continue; // to remove duplicacy

            for(int j = i+1;j<n-1;j++){
                 if (j>i+1 && nums[j] == nums[j-1]) continue; // to remove duplicasy

                for(int k = j+1 ;k<n; k++){
                    if (k>j+1 && nums[k] == nums[k-1]) continue; // to remove duplicasy

                   long long target1 = (long long)target - nums[i] - nums[j] - nums[k];

                    int l = k + 1, r = n - 1;

                    while(l<=r){
                        int mid = (l+r)/2;
                        if(nums[mid]==target1){
                            result.push_back({nums[i],nums[j],nums[k],nums[mid]});
                            break;
                        }else if(nums[mid]>target1){
                            r = mid -1;
                        }else{
                            l = mid+1;
                        }
                    }
                }

            }
        }
        return result;
   }
};