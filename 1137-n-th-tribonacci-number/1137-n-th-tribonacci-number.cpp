class Solution {
public:
    int dp[40];
    int solve(int n){
        if(n==0)return 0;
        if(n==1)return 1;
        if(n==2)return 1;

        if(dp[n]!=-1)return dp[n];

        int tn=0;

        tn+=solve(n-1);
        tn+=solve(n-2);
        tn+=solve(n-3);

        return dp[n]=tn;
    }

    int tribonacci(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};