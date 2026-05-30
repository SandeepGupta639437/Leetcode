class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve(vector<int>& nums, int target,int i,int j){
        if(i==n-1)return 0;
        if(i>=n || j>=n)return -1e9;
        int take = -1e9,skip = -1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        if(abs(nums[i]-nums[j])<=target){
            take = 1 + solve(nums,target,j,j+1);  
            skip = solve(nums,target,i,j+1);
        }else{
            skip = solve(nums,target,i,j+1);
        }
        return dp[i][j] = max(take,skip);
    }
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(nums,target,0,1);
        return (ans<0)?-1:ans;
    }
};