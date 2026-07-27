class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n+1,0);
        dp[0] = 1;

        double currProbabSum =  (k==0) ? 0 : 1;

        for(int i=1;i<=n;i++){
            dp[i] = currProbabSum / maxPts;
            if(i<k) currProbabSum += dp[i];
            if(i>=maxPts && i-maxPts<k){
                currProbabSum -= dp[i-maxPts];
            }
        }
        return accumulate(begin(dp)+k,end(dp),0.0);
    }
};