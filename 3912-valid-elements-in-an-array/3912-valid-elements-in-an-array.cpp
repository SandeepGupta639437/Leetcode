class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans,suff(n),pref(n);
        pref[0]=nums[0];
        for(int i = 1;i<n;i++){
            pref[i]=max(pref[i-1],nums[i]);
        }
        suff[n-1]=nums[n-1];
        for(int i = n-2;i>=0;i--){
            suff[i]=max(suff[i+1],nums[i]);
        }
        ans.push_back(nums[0]);
        for(int i=1;i<n-1;i++){
            if((nums[i]>pref[i-1])||(nums[i]>suff[i+1]))ans.push_back(nums[i]);
        }
        if(n>1)ans.push_back(nums[n-1]);
        return ans;
    }
};