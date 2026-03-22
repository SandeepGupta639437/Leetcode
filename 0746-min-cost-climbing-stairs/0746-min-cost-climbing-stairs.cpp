class Solution {
public:
    int dp[10000];

    int solve(vector<int>& cost,int i){
        if(i>=cost.size())return 0;
        if(dp[i]!=-1)return dp[i];

        int step1 = cost[i]+solve(cost,i+1);
        int step2 = cost[i]+solve(cost,i+2);

        return dp[i] = min(step1,step2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int op1=solve(cost,1);
        int op2=solve(cost,0);

        return min(op1,op2);
    }
};