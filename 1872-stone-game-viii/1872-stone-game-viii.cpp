class Solution {
public:
    int n;
    int dp[100001];
    vector<int>pref;

    // int solve(int i){
    //     if(i==n-1)return pref[n-1];

    //     if(dp[i]!=-1)return dp[i];

    //     int take = pref[i] - solve(i+1);
    //     int skip = solve(i+1);

    //     return dp[i] = max(skip,take);
    // }

    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        pref.resize(n,0);
        pref[0] = stones[0];

        // memset(dp,0,sizeof(dp));

        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + stones[i];
        }

        dp[n-1] = pref[n-1];

        for(int i = n-2 ; i>=1 ; i--){
            int take = pref[i] - dp[i+1];
            int skip = dp[i+1];
            dp[i] = max(skip,take);
        }
        return dp[1];
    }
};