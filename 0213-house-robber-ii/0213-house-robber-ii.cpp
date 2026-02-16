class Solution {
public:
    int t[101];
    int solve(vector<int>& nums,int i,int j){
        if(i>=j)return 0;
        if(t[i]!=-1)return t[i];
        int skip = solve(nums,i+1,j);
        int take = nums[i]+solve(nums,i+2,j);
        return t[i]=max(skip,take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        memset(t,-1,sizeof(t));
        int case1=solve(nums,0,n-1);
        memset(t,-1,sizeof(t));
        int case2=solve(nums,1,n);
        return max(case1,case2);
    }
};