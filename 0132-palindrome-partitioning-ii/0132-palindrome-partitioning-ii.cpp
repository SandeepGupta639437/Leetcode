class Solution {
public:
//     int dp[2001][2001];
//     int palin[2001][2001];
//     bool isPalindrome(string& s,int i,int j){
//         while(i<j){
//             if(s[i]!=s[j])return false;
//             i++;
//             j--;
//         }
//         return true;
//     }
//     int solve(string s, int i,int j){
//         if(i>=j)return 0;
//         if(palin[i][j])return 0;
        
//         int ans = INT_MAX;
//         if(dp[i][j]!=-1)return dp[i][j];
//         for(int k = i;k<=j-1;k++){
//             int temp = 1 + solve(s,i,k) + solve(s,k+1,j);
//             ans = min(ans,temp);
//         }
//         return dp[i][j] = ans;
//     }
    int minCut(string s) {
        int n = s.length();

        vector<vector<bool>>t(n,vector<bool>(n,false));
        for(int i=0;i<n;i++)t[i][i] = true;
        for(int L =2;L<=n;L++){
            for(int i=0;i<n-L+1;i++){
                int j = i+L-1;
                if(L==2){
                    t[i][j] = (s[i]==s[j]);
                }else{
                    t[i][j] = (s[i]==s[j]) && t[i+1][j-1];
                }
            }
        }

        vector<int>dp(n);
        for(int i=0;i<n;i++){
            if(t[0][i]==true){
                dp[i] = 0;
            }else{
                dp[i] = INT_MAX;
                for(int k=0;k<i;k++){
                    if(t[k+1][i] ==true && 1+dp[k] < dp[i]){
                        dp[i] = 1+dp[k];
                    }
                }
            }
        }

        return dp[n-1];
    }
};