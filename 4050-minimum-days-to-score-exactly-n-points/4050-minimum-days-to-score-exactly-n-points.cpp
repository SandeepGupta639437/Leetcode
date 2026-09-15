class Solution {
public:
    int minDays(int n) {
        const int INF = 1e9;

        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        for(int score = 0; score <= n; score++) {
            if(dp[score] == INF) continue;

            for(int len = 1; ; len++) {
                int points = len * (len + 1) / 2;

                if(score + points > n) break;

                int cost = len;

                if(score > 0)cost++;  // skip before starting new streak

                dp[score + points] = min(dp[score + points], dp[score] + cost);
            }
        }

        return dp[n];
    }
};