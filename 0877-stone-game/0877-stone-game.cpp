class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,vector<int>& piles){
        if(i==j)return piles[i];

        if(dp[i][j]!=-1)return dp[i][j];

        int takeLeft = piles[i] - solve(i+1,j,piles);
        int takeRight = piles[j] - solve(i,j-1,piles);

        return dp[i][j] = max(takeLeft,takeRight);
    }
    bool stoneGame(vector<int>& piles) {
        int n= piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,piles)>=0;
    }
};