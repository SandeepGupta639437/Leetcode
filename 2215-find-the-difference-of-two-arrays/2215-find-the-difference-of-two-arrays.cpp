class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mpp;
        vector<vector<int>>ans(2);
        for(int it:nums2){
            mpp[it]=1;
        }
        for(int it:nums1){
            if(mpp[it]!=1){
                ans[0].push_back(it);
                mpp[it]=1;
            }
        }
        mpp.clear();
        for(int it:nums1){
            mpp[it]=1;
        }
        for(int it:nums2){
            if(mpp[it]!=1){
                ans[1].push_back(it);
                mpp[it]=1;
            }
        }
        return ans;
    }
};