class Solution {
public:
    string states[12] = {"RYG","RGY","RYR","RGR","YRG","YGR","YGY","YRY","GRY","GYR","GRG","GYG"};
    int MOD = 1e9+7;
    int dp[5001][13];

    int solve(int n,int prev){
        if(n==0)return 1;

        int result = 0;

        if(dp[n][prev]!=-1)return dp[n][prev];

        string last = states[prev];

        for(int curr=0;curr<12;curr++){
            if(curr == prev)continue;

            bool conflict = false;
            string currPat = states[curr];

            for(int i=0;i<3;i++){
                if(currPat[i]==last[i]){
                    conflict = true;
                    break;
                }
            }

            if(!conflict){
                result = (result + solve(n-1,curr))%MOD;
            }
        }

        return dp[n][prev] = result;
    }

    int numOfWays(int n) {
        int result = 0;

        memset(dp,-1,sizeof(dp));

        for(int i=0;i<12;i++){
            result = (result + solve(n-1,i))%MOD;
        }

        return result;

    }
};