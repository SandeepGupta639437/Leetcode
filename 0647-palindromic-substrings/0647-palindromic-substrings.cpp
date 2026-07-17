class Solution {
public:
    int dp[1001][1001];
    int countSubstrings(string s) {
        int n = s.length();
        memset(dp,false,sizeof(dp));
        int ans = 0;
        for(int i = 0;i<n;i++){
            dp[i][i] =true;
            ans++;
            if(i<n-1){
                if(s[i]==s[i+1]){
                    dp[i][i+1] = true; 
                    ans++;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};