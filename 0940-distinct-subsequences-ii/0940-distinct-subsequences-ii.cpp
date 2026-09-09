class Solution {
public:
    int M = 1e9+7;
    int dp[2001];
    vector<int>prev;

    // int solve(int n){
    //     if(n==0)return 1;
    //     if(dp[n]!=-1)return dp[n];

    //     int total = ((1LL*2*solve(n-1))%M);

    //     if(prev[n] != 0){
    //         int duplicates = solve(prev[n]-1);
    //         total = (total-duplicates+M)%M;
    //     }

    //     return dp[n] = total;
    // }


    int distinctSubseqII(string s) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        prev.assign(n+1,0);

        vector<int>lastSeen(26,0);
        for(int i=1;i<=n;i++){
            int idx = s[i-1] - 'a';
            prev[i] = lastSeen[idx] ; // lastSeen stores the charater last time visited so that we casn remove duplicated
            lastSeen[idx] = i; 
        }

        // bottom up

        dp[0] = 1;

        for(int i=1;i<=n;i++){
            int total = (1LL*2*dp[i-1])%M;
            if(prev[i]!=0){
                int duplicates = dp[prev[i]-1];
                total = (total - duplicates + M)%M;
            }
            dp[i] = total;
        }

        return (dp[n]-1+M)%M;

        // return (solve(n)-1+M)%M; // top down
    }
};



// class Solution {
//     static constexpr int MOD = 1e9 + 7;

// public:
//     int distinctSubseqII(string s) {
//         int tot = 0, dp[26]{};

//         for (auto& c : s) {
//             c -= 'a';
//             int add = (tot - dp[c] + MOD) % MOD;
//             dp[c] = 1 + tot;
//             tot = (dp[c] + add) % MOD;
//         }

//         return tot;
//     }
// };
// // https://leetcode.com/problems/distinct-subsequences-ii/solutions/8506448/solution-by-la_castille-zs7g