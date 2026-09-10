class Solution {
public:
    int n;
    long long dp[101][101];
    vector<vector<int>>directions = {{1,-1},{1,0},{1,1}};
    int pathSum(vector<vector<int>>& matrix,int i,int j){
        if(i == n-1) return matrix[i][j];

        if(dp[i][j]!=-1e9)return dp[i][j];

        int ans = INT_MAX;
        for(auto &dir: directions ){
            int newX = i + dir[0];
            int newY = j + dir[1];

            if(newX>=n || newX<0 || newY>=n || newY<0)continue;

            ans = min(ans,matrix[i][j] + pathSum(matrix,newX,newY));
        }

        return dp[i][j] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        n = matrix.size();
        fill(&dp[0][0], &dp[0][0] + 101 * 101, -1e9);
        for(int j=0;j<n;j++){
            ans = min(ans,pathSum(matrix,0,j));
        }
        return ans;
    }
};