class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size()-1;
        for(int i=1;i<=n;i++){
           if(nums[i-1]!=i)return false;
        }
        if(nums[n]==n)return true;
        return false;
    }
};