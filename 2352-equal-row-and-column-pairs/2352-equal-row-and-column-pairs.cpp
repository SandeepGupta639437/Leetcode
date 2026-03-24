class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int cnt=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                int flag=1;
                for(int i=0;i<n;i++){
                    if(grid[r][i]!=grid[i][c]){
                        flag=0;
                        break;
                    }
                }
                if(flag)cnt++;
            }
        }
        return cnt;
    }
};