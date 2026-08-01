class Solution {
public:

    int n;
    int dp[501];

    int solve(vector<int>& arr,int i,int k){
        if(i>=n) return 0;

        int ans = 0;

        int mx = 0;
        if(dp[i]!=-1)return dp[i];

        for(int len=1; len<=k && i+len-1<n; len++){

            mx = max(mx, arr[i+len-1]);

            ans = max(ans, mx*len + solve(arr,i+len,k));
        }

        return dp[i] =  ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        n = arr.size();
        memset(dp,-1,sizeof(dp));

        return solve(arr,0,k);
    }
};