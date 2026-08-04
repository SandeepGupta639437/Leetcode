class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(begin(nums),end(nums));
        int maxi = *max_element(begin(nums),end(nums));
        set<int>st(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=mini;i<=maxi;i++){
            if(st.count(i)==0)ans.push_back(i);
        }
        return ans;
    }
};