class Solution {
public:
    int n;
    int dp[50001];
    int solve(vector<int> &stones,int i){
        if(i>=n)return 0;
        
        if(dp[i] != INT_MIN)return dp[i];

        int result = stones[i] - solve(stones,i+1);
        if(i+1<n) result = max(result,stones[i]+stones[i+1]-solve(stones,i+2));
        if(i+2<n) result = max(result,stones[i]+stones[i+1]+stones[i+2]-solve(stones,i+3));
        return dp[i] = result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        fill(dp, dp + n, INT_MIN);
        int diff = solve(stoneValue,0);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};