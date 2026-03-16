class Solution {
public:
    vector<vector<int>> dp;

    bool solve(string &s, string &p, int i, int j){
        if(i==s.size() && j==p.size()) return true;
        if(j==p.size()) return false;

        if(dp[i][j] != -1) return dp[i][j];

        if(i < s.size() && (s[i]==p[j] || p[j]=='?')){
            return dp[i][j] = solve(s,p,i+1,j+1);
        }

        if(p[j]=='*'){
            if(i < s.size() && solve(s,p,i+1,j)) return dp[i][j]=1;
            if(solve(s,p,i,j+1)) return dp[i][j]=1;
        }

        return dp[i][j]=0;
    }

    bool isMatch(string s, string p) {
        dp.resize(s.size()+1, vector<int>(p.size()+1,-1));
        return solve(s,p,0,0);
    }
};