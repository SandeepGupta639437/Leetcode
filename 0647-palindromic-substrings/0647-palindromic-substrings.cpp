class Solution {
public:
    int dp[1001][1001];
    bool check(int i,int j, string& s){
        if(i>j)return true;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==s[j]){
          return dp[i][j] = check(i+1,j-1,s);
        }
        return dp[i][j] = false;
    }
    int countSubstrings(string s) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i,j,s))ans++;
            }
        }
        return ans;
    }
};