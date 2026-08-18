class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++)mpp[nums[i]]++;
        int ans = -1;
        int num = INT_MIN;
        if(mpp[nums[0]] == 1){
            ans =  nums[0];
            num = nums[0];
        }

        if(mpp[nums[n-1]]==1 && num<nums[n-1])ans =  nums[n-1];

        if(k==1){
            for(int i=0;i<n;i++){
                if(mpp[nums[i]]==1 && nums[i]>=num){
                    ans = nums[i];
                    num = nums[i];
                }
            }
        }

        if(k==n){
            ans = *max_element(begin(nums),end(nums));
        }

        return ans;
    }
};