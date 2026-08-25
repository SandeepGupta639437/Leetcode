class Solution {
public:
    int n ;
    int dp[50001];
    int solve(vector<int> &stone,int i){
        if(i>=n)return 0;
        int op1 = INT_MIN;
        int op2 = INT_MIN;
        int op3 = INT_MIN;
        if(dp[i]!=-1)return dp[i];
        if(i+2<n)
            op1 = (stone[i] + stone[i+1] + stone[i+2]) - solve(stone,i+3);
        if(i+1<n)
            op2 = (stone[i] + stone[i+1]) - solve(stone,i+2);
        if(i<n)
            op3 = (stone[i]) - solve(stone,i+1);

        return dp[i] = max({op1,op2,op3});
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        memset(dp,-1,sizeof(dp));
        int val = solve(stoneValue,0);
        if(val<0)return "Bob";
        if(val>0)return "Alice";
        return "Tie";
    }
};