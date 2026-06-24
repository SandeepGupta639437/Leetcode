class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        long long MOD = 1e9 + 7;
        int m = r-l+1;
        vector<long long>dp(m,1);
        bool reverseC = true;
        for(int len = 2; len <= n; len++){
            long long sum = 0;
            if(reverseC){
                for(int i = m-1 ; i >= 0; i--){
                    int val = dp[i];
                    dp[i] = sum;
                    sum = (sum+val) % MOD;
                }
            }else{
                for(int i = 0; i < m; i++){
                    int val = dp[i];
                    dp[i] = sum;
                    sum = (sum+val)%MOD;
                }
            }
            reverseC = !reverseC;
        }
        return ((accumulate(dp.begin(),dp.end(),0LL)%MOD) << 1)% MOD;
    }
};