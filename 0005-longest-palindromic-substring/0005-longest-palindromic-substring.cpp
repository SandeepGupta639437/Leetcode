class Solution {
public:
    int dp[1001][1001];
    int maxi = 0;
    int idx = 0,idy=0;

    bool check(string& s,int i,int j){
        if(i>=j)return 1;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==s[j])
            return dp[i][j] = check(s,i+1,j-1);

        return dp[i][j] = 0;
    }
    string longestPalindrome(string s) {
       memset(dp,-1,sizeof(dp));
       int start = 0;
       int n = s.length();
       for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(check(s,i,j)){
                if(maxi < j-i+1){
                    maxi = j-i+1;
                    start = i;
                }
            }
        }
       }
       return s.substr(start,maxi);
    }
};