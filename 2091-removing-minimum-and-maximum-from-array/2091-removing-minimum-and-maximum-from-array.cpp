class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = min_element(nums.begin(),nums.end()) - nums.begin();;
        int maxIdx = max_element(nums.begin(),nums.end()) - nums.begin();;
        int ans = n;
        int first = min(minIdx,maxIdx)+1;
        int lastIdx = max(minIdx,maxIdx)+1;
        ans = min(ans,first+n-lastIdx+1);
        ans = min(ans,lastIdx);
        ans = min(ans,n-first+1);

        return ans;
    }
};