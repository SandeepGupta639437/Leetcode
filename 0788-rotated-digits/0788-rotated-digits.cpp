class Solution {
public:
    int dp[100001];
    int solve(int n){
        if(dp[n]!=-1)return dp[n];
        if(n==0)return dp[n] =0;

        int remain = solve(n/10);
        if(remain == 2) return dp[n] = 2;
        int digit_check;
        int d = n%10;

        if(d==1 || d == 0 || d == 8)digit_check = 0;
        else if(d==2 || d==5 || d==6 || d==9) digit_check = 1;
        else return dp[n] = 2;

        if(digit_check == 0 && remain == 0)return dp[n] = 0;

        return dp[n]=1;
    }
    int rotatedDigits(int n) {
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int i = 1;i<=n;i++){
            if(solve(i)==1)ans++;
        }
        return  ans;
    }
};