class Solution {
public:
    using ll = long long;
    int dp[10010][301];
    ll solve(int amount , vector<int>& coins,int j){
        if(amount == 0)return 1;
        ll ways = 0;
        if(dp[amount][j]!=-1)return dp[amount][j];
        for(int i=j;i<coins.size();i++){
         if((amount-coins[i])>=0) ways += solve((amount-coins[i]),coins,i);
        }
        return dp[amount][j]=ways;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        sort(begin(coins),end(coins));
        int ans = solve(amount,coins,0);
        return ans;
    }
};