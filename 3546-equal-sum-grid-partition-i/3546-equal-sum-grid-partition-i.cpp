class Solution {
public:
    using ll = long long;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll totalSum = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                totalSum+=grid[i][j];
            }
        }
        ll rowSum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rowSum+=grid[i][j];
            }
            if(totalSum-rowSum==rowSum)return true;
        }
        ll colSum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                colSum+=grid[j][i];
            }
            if(totalSum-colSum==colSum)return true;
        }
        return false;
    }
};