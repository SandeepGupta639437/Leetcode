class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();vector<int>exists(101,0);for(int &it:nums)exists[it]=1;int i; for(i=k;i<=100;i+=k) if(exists[i]==0)return i;
        return i;
    }
};