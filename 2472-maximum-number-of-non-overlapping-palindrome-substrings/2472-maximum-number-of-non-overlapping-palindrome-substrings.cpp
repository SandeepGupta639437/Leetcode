class Solution {
public:
    int n;
    vector<vector<bool>> t;
    vector<int> dp;
    int solve(int i, string& s, int k) {
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        // Skip current character
        int ans = solve(i + 1, s, k);

        // Take palindrome starting at i
        for(int j = i + k - 1; j < n; j++) {
            if(t[i][j]) {
                ans = max(ans, 1 + solve(j + 1, s, k));
            }
        }

        return dp[i] = ans;
    }

    int maxPalindromes(string s, int k) {
        n = s.length();

        t.assign(n, vector<bool>(n, false));

        for(int i=0;i<n;i++)t[i][i] = true;
        
        for(int L = 2;L <= n;L++){
            for(int i=0;i<n-L+1;i++){
                int j = i+L-1;
                if(L==2){
                    t[i][j] = (s[i]==s[j]);
                }else{
                    t[i][j] = (s[i]==s[j]) && t[i+1][j-1];
                }
            }
        }

        dp.assign(n, -1);

        return solve(0,s,k);

    }
};