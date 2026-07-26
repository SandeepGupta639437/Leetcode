class Solution {
public:
    int dp[100001];
    bool solve(int i,string& s,int minJump,int maxJump){
        int n = s.size();
        if(i==n-1)return true;

        if(dp[i]!=-1)return dp[i];

        for(int jump = minJump; jump<= maxJump; jump++){
            if(i+jump<n && s[i+jump]=='0'){
                if(solve(i+jump,s,minJump,maxJump))return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        // memset(dp,-1,sizeof(dp));
        memset(dp,0,sizeof(dp));
        vector<int> prefix(n + 1, 0);
        prefix[n-1] = true;
        
        dp[0] = 1;
        int count =0;
        for(int i=1;i<n;i++){
            if(i-minJump >= 0){
                count+=dp[i - minJump];
            }
            if(i-maxJump-1 >= 0){
                count-=dp[i - maxJump-1];
            }
            if(count>0 && s[i]=='0'){
                dp[i] = 1;
            }
        }
        return dp[n-1]>0;
        
        // return solve (0,s,minJump,maxJump);
    }
};