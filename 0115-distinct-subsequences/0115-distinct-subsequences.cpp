class Solution {
public:
    int n,m;
    int dp[1001][1001];

    int solve(int i,int j,string &s,string &t){

        if(j==m) return dp[i][j] = 1;
        if(i==n) return dp[i][j] = 0;
        
        if(dp[i][j]!=-1)return dp[i][j];

        int ans = 0;

        if(s[i]==t[j])ans +=solve(i+1,j+1,s,t);
        ans += solve(i+1,j,s,t);

        return dp[i][j] = ans;        
    }

    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        n=s.size();
        m=t.size();

        return solve(0,0,s,t);
    }
};