class Solution {
public:
    int m, n;
    int dp[201][201];

    int solve(int i, int j, vector<vector<int>>& dungeon) {
        if (i == m - 1 && j == n - 1) {
            return max(1, 1 - dungeon[i][j]);   /// (1-dungeon[i][j]) - > abs(dungeon[i][j]) + 1; if(dungeon[i][j]<0)
        }

        if (dp[i][j] != -1) return dp[i][j];

        int right = INT_MAX;
        int down = INT_MAX;

        if (j + 1 < n) right = solve(i, j + 1, dungeon);

        if (i + 1 < m) down = solve(i + 1, j, dungeon);

        int next = min(right, down);

        return dp[i][j] = max(1, next - dungeon[i][j]);  //same here also ..concept 
        //  video : https://www.youtube.com/watch?v=Mlcy-9hB6Jc
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, dungeon);
    }
};