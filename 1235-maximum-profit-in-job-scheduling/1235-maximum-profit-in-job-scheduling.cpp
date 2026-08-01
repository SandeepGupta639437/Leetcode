class Solution {
public:
    int n;
    int dp[500001];
    int getNextIdx(int i,vector<vector<int>>& v){
        int val = v[i][1];
        int l = i+1, r =  n-1;
        int ans = -2;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(v[mid][0]>=val){
                r =  mid-1;
                ans = mid;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
    int solve(int i,vector<vector<int>>& v){
        if(i>=n || i<0)return 0;

        if(dp[i]!=-1)return dp[i];

        int idx = getNextIdx(i,v);

        int take = v[i][2] + solve(idx,v);
        int skip = solve(i+1,v); 

        return dp[i] = max(take,skip);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        n = startTime.size();
        vector<vector<int>>v(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            v[i][0] = startTime[i];
            v[i][1] = endTime[i];
            v[i][2] = profit[i];
        }
        sort(begin(v),end(v),[&](const auto& a,const auto& b){
            return a[0]<b[0];
        });

        return solve(0,v);
    }
};