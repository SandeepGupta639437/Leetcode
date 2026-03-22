class Solution {
public:
    using ll = long long;
    int n;
    ll dp[2][1001];
    const int MOD = 1e9+7;

    ll solve(int half, int tiles){
        if(tiles == n) return (half == 0);
        if(tiles > n) return 0;

        if(dp[half][tiles] != -1) return dp[half][tiles];

        ll t = 0;
        if(half==0){
            t=(t+solve(0,tiles+1))%MOD; // vertical
            t=(t+solve(0,tiles+2))%MOD; //two horizontal
            t=(t+2*solve(1,tiles+2))%MOD; //L and opposite L
        }
        else{
            t=(t+solve(0,tiles+1))%MOD; // L
            t=(t+solve(1,tiles+1))%MOD; // horizontal
        }
        return dp[half][tiles] = t;
    }

    int numTilings(int n_) {
        n = n_;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};