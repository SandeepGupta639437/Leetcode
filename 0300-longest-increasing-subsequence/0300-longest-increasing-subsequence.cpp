class Solution {
public: 
    const static int N = 25e2+10;
    int dp[N];
    int lis(vector<int>& a,int i){
        if(dp[i]!=-1)return dp[i];
        int ans =1;
        for(int j=0;j<i;j++){
            if(a[i]>a[j])ans = max(ans,lis(a,j)+1);
        }
        return dp[i]=ans;
    }
    int lengthOfLIS(vector<int>& a) {
        memset(dp,-1,sizeof(dp));
        int n=a.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans = max(ans,lis(a,i));
        }
        return ans;
    }
};