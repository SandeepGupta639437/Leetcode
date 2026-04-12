class Solution {
public:
    int n;
    
    vector<pair<int,int>> coords = {
        {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5}, // A-F
        {1,0}, {1,1}, {1,2}, {1,3}, {1,4}, {1,5}, // G-L
        {2,0}, {2,1}, {2,2}, {2,3}, {2,4}, {2,5}, // M-R
        {3,0}, {3,1}, {3,2}, {3,3}, {3,4}, {3,5}, // S-X
        {4,0}, {4,1}                              // Y-Z
    };

    int dp[301][27][27]; // 26 letters + 1 for "not used"

    int dist(int a, int b) {
        if (a == 26) return 0; // unused finger → no cost
        auto [x1, y1] = coords[a];
        auto [x2, y2] = coords[b];
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(string &word, int i, int f1, int f2) {
        if (i == n) return 0;

        if (dp[i][f1][f2] != -1) return dp[i][f1][f2];

        int curr = word[i] - 'A';

        // Option 1: use finger 1
        int useF1 = dist(f1, curr) + solve(word, i + 1, curr, f2);

        // Option 2: use finger 2
        int useF2 = dist(f2, curr) + solve(word, i + 1, f1, curr);

        return dp[i][f1][f2] = min(useF1, useF2);
    }

    int minimumDistance(string word) {
        n = word.size();
        memset(dp, -1, sizeof(dp));

        // 26 means "finger not placed yet"
        return solve(word, 0, 26, 26);
    }
};