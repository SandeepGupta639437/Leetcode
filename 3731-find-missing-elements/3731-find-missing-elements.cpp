class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(begin(nums),end(nums));
        int maxi = *max_element(begin(nums),end(nums));
        map<int,int>mp;
        for(int it:nums)mp[it] = 1;
        vector<int>ans;
        for(int i=mini;i<=maxi;i++){
            if(!mp[i])ans.push_back(i);
        }
        return ans;
    }
};