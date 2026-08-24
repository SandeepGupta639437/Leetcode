class Solution {
public:
    int n ;
    int dp[101][101];
    int solve(vector<int> &piles,int m,int i){
        if(i>=n)return 0;
        if(dp[i][m]!=-1)return dp[i][m];

        int ans =0;
        int total = 0;

        for(int k = i ; k < n;k++) total += piles[k];

        for (int x = 1; x <= 2 * m && i + x <= n; x++){
            int oponent = solve(piles,max(m,x),i+x);
            ans = max(ans,total-oponent);
        }

        return dp[i][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(piles,1,0);
    }
};