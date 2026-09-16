class Solution {
public:
    int dp[1001][1001];
    int MOD = 1e9+7;
    int solve(int n , int k){
        if(k==1){
            return n*(n-1)/2;
        }
        if(n==1)return 0;
        if(n-1==k)return 1;
        if(n-1<k)return 0;

        if(dp[n][k]!=-1)return dp[n][k];

        int total = 0;
        total = (total + solve(n-1,k))%MOD;

        for(int i=1;i<n;i++){
            total = (total + solve(n-i,k-1))%MOD;
        }
        return dp[n][k] = total;
    }
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        // memset(prefdp,-1,sizeof(prefdp));
        return solve(n,k);
    }
};