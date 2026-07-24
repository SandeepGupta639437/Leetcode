class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                st.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int>ans;
        for(int i=0;i<n;i++){
            for(auto it:st){
                ans.insert(it^nums[i]);
            }
        }
        return ans.size();
    }
};