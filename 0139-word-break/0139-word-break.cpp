class Solution {
public:
    unordered_set<string>st;
    int n;
    int dp[301];
    bool solve(int i,string& s){
        if(i>=n)return true;

        if(dp[i]!=-1)return dp[i];
        if(st.find(s)!=st.end())return dp[i]= true;

        for(int l = 1;l<=n;l++){
            string temp = s.substr(i,l);
            if(st.find(temp)!=st.end() && solve(l+i,s)){
                return dp[i]=true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        memset(dp,-1,sizeof(dp));
        for(string& it:wordDict){
            st.insert(it);
        }
        return solve(0,s);
    }
};