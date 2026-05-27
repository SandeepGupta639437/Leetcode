class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = n+1;
        vector<int>prefMax(n+1),sufMin(n+1);
        prefMax[0] = nums[0];
        sufMin[n] = INT_MAX;
        for(int i =1;i<n;i++){
            prefMax[i] = max(nums[i],prefMax[i-1]);
        }
        for(int i = n-1;i>=0;i--){
            sufMin[i] = min(sufMin[i+1],nums[i]);
        }

        for(int i=0;i<n;i++){
            if(prefMax[i]-sufMin[i] <=k)ans=min(ans,i);
        }
        if(ans==n+1)return -1;
        return ans;
    }
};