class Solution {
public:
    int dp[501];
    int solve(int n){
        if(n==1)return 0;
        if(dp[n]!=-1)return dp[n];
        int a=n/2;
        int b=n-a;
        return dp[n] = a*b + solve(a) + solve(b);
    }
    int minCost(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};