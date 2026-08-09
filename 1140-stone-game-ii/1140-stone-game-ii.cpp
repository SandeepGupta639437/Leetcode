class Solution {
public:
    int dp[101][101][2];
    int n;
    int solve(int turn,int i, vector<int>& piles, int M) {

        if (i > n) return 0;

        if(dp[i][M][turn]!=-1)return dp[i][M][turn];

        int ans = 0;
        int sum = 0;
        if (turn == 1)
            ans = 0;       // Alice wants maximum
        else
            ans = 1e9;     // Bob wants minimum

        for (int x = 1; x <= 2 * M && i + x - 1 <= n; x++) {

            sum += piles[i + x - 1];

            if(turn==1){
                ans = max(ans,sum+solve(0,i+x,piles,max(x,M)));
            }else{
                ans = min(ans,solve(1,i+x,piles,max(x,M)));
            }
        }

        return dp[i][M][turn] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size()-1;
        memset(dp,-1,sizeof(dp));

        return solve(1,0, piles, 1);
    }
};