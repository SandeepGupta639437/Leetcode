class Solution {
public:
    int n;
    int dp[1001][1001];
    vector<int>pref;
    int solve(vector<int> &stones,int i,int j){
        if(i>j)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int left = (pref[j]-pref[i]) - solve(stones,i+1,j);
        int right = (((j>0)?pref[j-1]:0)-((i>0)?pref[i-1]:0)) - solve(stones,i,j-1);

        return dp[i][j] = max(left,right);
    }
    int stoneGameVII(vector<int>& stones) {
      n = stones.size();
      memset(dp,-1,sizeof(dp));
      pref.resize(n,0);

      pref[0]=stones[0];
      for(int i=1;i<n;i++)pref[i] = pref[i-1] + stones[i];

      return solve(stones,0,n-1);  
    }
};