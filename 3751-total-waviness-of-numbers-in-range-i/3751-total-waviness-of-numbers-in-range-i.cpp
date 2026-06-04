class Solution {
public:
    int dp[100005];
    int waviness(int n) {
        int p = n;
        if (n < 100) return 0;
        int cnt = 0;
        if(dp[n]!=-1)return dp[n];
        int r = n % 10;n /= 10;
        int m = n % 10;n /= 10;
        while (n) {
            int l = n % 10;
            if ((m > l && m > r) || (m < l && m < r))cnt++;
            if(dp[n]!=-1){
                r = m;
                m = l;
                l = (n/10)%10;
                if ((m > l && m > r) || (m < l && m < r))cnt++;
                return cnt+dp[n];
            }
            r = m;
            m = l;
            n /= 10;
        }
        return dp[p] = cnt;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int i=num1;i<=num2;i++){
            ans+=waviness(i);
        }
        return ans;
    }
};