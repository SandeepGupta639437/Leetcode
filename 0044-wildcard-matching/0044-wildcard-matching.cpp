class Solution {
public:
    int dp[2001][2001];

    bool solve(string &s, string &p, int i, int j){
        if(i==s.size() && j==p.size())return dp[i][j]=true;;
        if(j==p.size()) return false;

        if(dp[i][j]!=-1)return dp[i][j];

        if(i==s.size()){
            if(p[j]=='*')return dp[i][j]=solve(s,p,i,j+1);
            return false;
        }
        
        if(p[j]=='?' || (s[i]==p[j]))return dp[i][j]= solve(s,p,i+1,j+1);
        else if(p[j]=='*'){
            return dp[i][j]= (solve(s,p,i+1,j)||solve(s,p,i,j+1));
        }
        else return false;

    }

    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return solve(s,p,0,0);
    }
};