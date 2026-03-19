class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> cntX(m, vector<int>(n, 0));
        vector<vector<int>> cntY(m, vector<int>(n, 0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]=='X')cntX[i][j]++;
               else if(grid[i][j]=='Y')cntY[i][j]++;
            }
        }
        for(int i=0;i<m;i++){
            for(int j = 1; j < n; j++){
               cntX[i][j]+=cntX[i][j-1];
               cntY[i][j]+=cntY[i][j-1];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
               cntX[j][i]+=cntX[j-1][i];
               cntY[j][i]+=cntY[j-1][i];
            }
        }

        int ans = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(cntX[i][j]==cntY[i][j] && cntX[i][j]>0) ans++;
            }
        }
        return ans;
    }
};