class Solution {
public:
    using ll = long long;
    int dp[10010];
    ll solve(int amount , vector<int>& coins){
        if(amount == 0)return 0;
        ll ans = INT_MAX;
        if(dp[amount]!=-1)return dp[amount];
        for(int it:coins){
           if((amount-it)>=0) ans = min((ans+0LL) , (solve(amount-it,coins)+1LL));
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins,int amount) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(amount,coins);
        return (ans==INT_MAX)?-1:ans;
    }
};