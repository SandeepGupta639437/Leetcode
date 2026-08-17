class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& pref,int l,int r){
        if(l>=r)return 0;
        int score = 0;

        if(dp[l][r]!=-1)return dp[l][r];

        for(int mid=l;mid<r;mid++){
            int leftSum = pref[mid] -((l>0)?pref[l-1]:0);
            int rightSum = pref[r] - pref[mid];

            if(leftSum<rightSum){
                score = max(score,leftSum+solve(pref,l,mid));
            }else if(rightSum<leftSum){
                score = max(score,rightSum+solve(pref,mid+1,r));
            }else{
                score = max({
                             score,
                             rightSum+solve(pref,mid+1,r),
                             leftSum+solve(pref,l,mid)
                            });
            }
        }

        return dp[l][r] = score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // memset(dp,-1,sizeof(dp));
        memset(dp,0,sizeof(dp));
        vector<int>pref(n,0);
        pref[0] = stoneValue[0];

        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + stoneValue[i];
        }

        for(int l = n-1;l>=0;l--){
            for(int r= l+1;r<n;r++){
                for(int mid=l;mid<r;mid++){
                    int leftSum = pref[mid] -((l>0)?pref[l-1]:0);
                    int rightSum = pref[r] - pref[mid];

                    if(leftSum<rightSum){
                        dp[l][r] = max(dp[l][r],leftSum+dp[l][mid]);
                    }else if(rightSum<leftSum){
                        dp[l][r] = max(dp[l][r],rightSum+dp[mid+1][r]);
                    }else{
                        dp[l][r] = max({dp[l][r], rightSum+dp[mid+1][r], leftSum+dp[l][mid] });
                    }
                }
            }
        }
        // return solve(pref,0,n-1);
        return dp[0][n-1];
    }
};